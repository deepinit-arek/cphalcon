
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

extern zend_class_entry *phalcon_dispatcherinterface_ce;

PHALCON_INIT_CLASS(Phalcon_DispatcherInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setactionsuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, actionSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setdefaultnamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, namespace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setactionname, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setparams, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setparam, 0, 0, 2)
	ZEND_ARG_INFO(0, param)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_getparam, 0, 0, 1)
	ZEND_ARG_INFO(0, param)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_forward, 0, 0, 1)
	ZEND_ARG_INFO(0, forward)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_dispatcherinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, setActionSuffix, arginfo_phalcon_dispatcherinterface_setactionsuffix)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, setDefaultNamespace, arginfo_phalcon_dispatcherinterface_setdefaultnamespace)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, setDefaultAction, arginfo_phalcon_dispatcherinterface_setdefaultaction)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, setActionName, arginfo_phalcon_dispatcherinterface_setactionname)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, getActionName, NULL)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, setParams, arginfo_phalcon_dispatcherinterface_setparams)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, getParams, NULL)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, setParam, arginfo_phalcon_dispatcherinterface_setparam)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, getParam, arginfo_phalcon_dispatcherinterface_getparam)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, isFinished, NULL)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, getReturnedValue, NULL)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, dispatch, NULL)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, forward, arginfo_phalcon_dispatcherinterface_forward)
	PHP_FE_END
};

