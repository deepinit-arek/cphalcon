
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"

/**
 * Phalcon\Validation\Validator\Between
 *
 * Validates that a value is between a range of two values
 *
 *<code>
 *use Phalcon\Validation\Validator\Between;
 *
 *$validator->add('name', new Between(array(
 *   'minimum' => 0,
 *   'maximum' => 100,
 *   'message' => 'The price must be between 0 and 100'
 *)));
 *</code>
 */


/**
 * Phalcon\Validation\Validator\Between initializer
 */
PHALCON_INIT_CLASS(Phalcon_Validation_Validator_Between){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Between, validation_validator_between, "phalcon\\validation\\validator", phalcon_validation_validator_between_method_entry, 0);

	zend_class_implements(phalcon_validation_validator_between_ce TSRMLS_CC, 1, phalcon_validation_validatorinterface_ce);

	return SUCCESS;
}

/**
 * Executes the validation
 *
 * @param Phalcon\Validation $validator
 * @param string $attribute
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_Between, validate){

	zval *validator, *attribute, *value, *option = NULL, *minimum;
	zval *maximum, *valid = NULL, *type, *message_str = NULL, *message;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &validator, &attribute) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(value);
	PHALCON_CALL_METHOD_PARAMS_1(value, validator, "getvalue", attribute);
	
	PHALCON_INIT_VAR(option);
	ZVAL_STRING(option, "minimum", 1);
	
	PHALCON_INIT_VAR(minimum);
	PHALCON_CALL_METHOD_PARAMS_1(minimum, this_ptr, "getoption", option);
	
	PHALCON_INIT_NVAR(option);
	ZVAL_STRING(option, "maximum", 1);
	
	PHALCON_INIT_VAR(maximum);
	PHALCON_CALL_METHOD_PARAMS_1(maximum, this_ptr, "getoption", option);
	
	PHALCON_INIT_VAR(valid);
	is_smaller_or_equal_function(valid, minimum, value TSRMLS_CC);
	if (zend_is_true(valid)) {
		is_smaller_or_equal_function(valid, value, maximum TSRMLS_CC);
	}
	
	if (PHALCON_IS_FALSE(valid)) {
	
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "Between", 1);
	
		PHALCON_INIT_NVAR(option);
		ZVAL_STRING(option, "message", 1);
	
		PHALCON_INIT_VAR(message_str);
		PHALCON_CALL_METHOD_PARAMS_1(message_str, this_ptr, "getoption", option);
		if (!zend_is_true(message_str)) {
			PHALCON_INIT_NVAR(message_str);
			PHALCON_CONCAT_VS(message_str, attribute, " is not between a valid range");
		}
	
		PHALCON_INIT_VAR(message);
		object_init_ex(message, phalcon_validation_message_ce);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(message, "__construct", message_str, attribute, type);
	
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(validator, "appendmessage", message);
		RETURN_MM_FALSE;
	}
	
	RETURN_MM_TRUE;
}

