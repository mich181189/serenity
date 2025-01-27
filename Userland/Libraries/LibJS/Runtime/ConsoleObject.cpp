/*
 * Copyright (c) 2020, Andreas Kling <kling@serenityos.org>
 * Copyright (c) 2020-2022, Linus Groh <linusg@serenityos.org>
 * Copyright (c) 2020, Emanuele Torre <torreemanuele6@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibJS/Console.h>
#include <LibJS/Runtime/ConsoleObject.h>
#include <LibJS/Runtime/GlobalObject.h>

namespace JS {

ConsoleObject::ConsoleObject(Realm& realm)
    : Object(*realm.global_object().object_prototype())
{
}

void ConsoleObject::initialize(Realm& realm)
{
    auto& vm = this->vm();
    Object::initialize(realm);
    u8 attr = Attribute::Writable | Attribute::Enumerable | Attribute::Configurable;
    define_native_function(realm, vm.names.log, log, 0, attr);
    define_native_function(realm, vm.names.debug, debug, 0, attr);
    define_native_function(realm, vm.names.info, info, 0, attr);
    define_native_function(realm, vm.names.warn, warn, 0, attr);
    define_native_function(realm, vm.names.error, error, 0, attr);
    define_native_function(realm, vm.names.trace, trace, 0, attr);
    define_native_function(realm, vm.names.count, count, 0, attr);
    define_native_function(realm, vm.names.countReset, count_reset, 0, attr);
    define_native_function(realm, vm.names.clear, clear, 0, attr);
    define_native_function(realm, vm.names.assert, assert_, 0, attr);
    define_native_function(realm, vm.names.group, group, 0, attr);
    define_native_function(realm, vm.names.groupCollapsed, group_collapsed, 0, attr);
    define_native_function(realm, vm.names.groupEnd, group_end, 0, attr);
    define_native_function(realm, vm.names.time, time, 0, attr);
    define_native_function(realm, vm.names.timeLog, time_log, 0, attr);
    define_native_function(realm, vm.names.timeEnd, time_end, 0, attr);
}

// 1.1.6. log(...data), https://console.spec.whatwg.org/#log
JS_DEFINE_NATIVE_FUNCTION(ConsoleObject::log)
{
    return vm.current_realm()->global_object().console().log();
}

// 1.1.3. debug(...data), https://console.spec.whatwg.org/#debug
JS_DEFINE_NATIVE_FUNCTION(ConsoleObject::debug)
{
    return vm.current_realm()->global_object().console().debug();
}

// 1.1.5. info(...data), https://console.spec.whatwg.org/#info
JS_DEFINE_NATIVE_FUNCTION(ConsoleObject::info)
{
    return vm.current_realm()->global_object().console().info();
}

// 1.1.9. warn(...data), https://console.spec.whatwg.org/#warn
JS_DEFINE_NATIVE_FUNCTION(ConsoleObject::warn)
{
    return vm.current_realm()->global_object().console().warn();
}

// 1.1.4. error(...data), https://console.spec.whatwg.org/#error
JS_DEFINE_NATIVE_FUNCTION(ConsoleObject::error)
{
    return vm.current_realm()->global_object().console().error();
}

// 1.1.8. trace(...data), https://console.spec.whatwg.org/#trace
JS_DEFINE_NATIVE_FUNCTION(ConsoleObject::trace)
{
    return vm.current_realm()->global_object().console().trace();
}

// 1.2.1. count(label), https://console.spec.whatwg.org/#count
JS_DEFINE_NATIVE_FUNCTION(ConsoleObject::count)
{
    return vm.current_realm()->global_object().console().count();
}

// 1.2.2. countReset(label), https://console.spec.whatwg.org/#countreset
JS_DEFINE_NATIVE_FUNCTION(ConsoleObject::count_reset)
{
    return vm.current_realm()->global_object().console().count_reset();
}

// 1.1.2. clear(), https://console.spec.whatwg.org/#clear
JS_DEFINE_NATIVE_FUNCTION(ConsoleObject::clear)
{
    return vm.current_realm()->global_object().console().clear();
}

// 1.1.1. assert(condition, ...data), https://console.spec.whatwg.org/#assert
JS_DEFINE_NATIVE_FUNCTION(ConsoleObject::assert_)
{
    return vm.current_realm()->global_object().console().assert_();
}

// 1.3.1. group(...data), https://console.spec.whatwg.org/#group
JS_DEFINE_NATIVE_FUNCTION(ConsoleObject::group)
{
    return vm.current_realm()->global_object().console().group();
}

// 1.3.2. groupCollapsed(...data), https://console.spec.whatwg.org/#groupcollapsed
JS_DEFINE_NATIVE_FUNCTION(ConsoleObject::group_collapsed)
{
    return vm.current_realm()->global_object().console().group_collapsed();
}

// 1.3.3. groupEnd(), https://console.spec.whatwg.org/#groupend
JS_DEFINE_NATIVE_FUNCTION(ConsoleObject::group_end)
{
    return vm.current_realm()->global_object().console().group_end();
}

// 1.4.1. time(label), https://console.spec.whatwg.org/#time
JS_DEFINE_NATIVE_FUNCTION(ConsoleObject::time)
{
    return vm.current_realm()->global_object().console().time();
}

// 1.4.2. timeLog(label, ...data), https://console.spec.whatwg.org/#timelog
JS_DEFINE_NATIVE_FUNCTION(ConsoleObject::time_log)
{
    return vm.current_realm()->global_object().console().time_log();
}

// 1.4.3. timeEnd(label), https://console.spec.whatwg.org/#timeend
JS_DEFINE_NATIVE_FUNCTION(ConsoleObject::time_end)
{
    return vm.current_realm()->global_object().console().time_end();
}

}
