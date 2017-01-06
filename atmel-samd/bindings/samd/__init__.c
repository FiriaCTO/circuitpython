/*
 * This file is part of the Micro Python project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Scott Shawcroft for Adafruit Industries
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
 #include "py/obj.h"
 #include "py/runtime.h"
 #include "autoreset.h"

//| :mod:`samd` --- SAMD implementation settings
//| =================================================
//|
//| .. module:: samd
//|   :synopsis: SAMD implementation settings
//|   :platform: SAMD21
//|

//| .. method:: enable_autoreset()
//|
//|   Enable autoreset based on USB file write activity.
//|
STATIC mp_obj_t samd_enable_autoreset(void) {
    autoreset_enable();
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_0(samd_enable_autoreset_obj, samd_enable_autoreset);

//| .. method:: disable_autoreset()
//|
//|   Disable autoreset based on USB file write activity until the next reset
//|   or until `enable_autoreset` is called.
//|
STATIC mp_obj_t samd_disable_autoreset(void) {
    autoreset_disable();
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_0(samd_disable_autoreset_obj, samd_disable_autoreset);

STATIC const mp_rom_map_elem_t samd_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_samd) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_enable_autoreset),  MP_ROM_PTR(&samd_enable_autoreset_obj)},
    { MP_OBJ_NEW_QSTR(MP_QSTR_disable_autoreset),  MP_ROM_PTR(&samd_disable_autoreset_obj)},
};

STATIC MP_DEFINE_CONST_DICT(samd_module_globals, samd_module_globals_table);

const mp_obj_module_t samd_module = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&samd_module_globals,
};
