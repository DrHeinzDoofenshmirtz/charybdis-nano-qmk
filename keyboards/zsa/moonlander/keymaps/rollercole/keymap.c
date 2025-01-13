#include "features/achordion.h"
// gogo
//
#include QMK_KEYBOARD_H

#define __________ _______

#define ROLLERCOLE_36(_q, _w, _f, _p, _b, _j, _l, _u, _y, _quote, _a, _r, _s, _t, _g, _m, _n, _e, _i, _o, _z, _x, _c, _d, _v, _k, _h, _comm, _dot, _min, _thumbL, _thumbR) \
LAYOUT(\
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,\
        _______,      _q,      _w,      _f,      _p,      _b, _______,           _______,      _j,      _l,      _u,      _y,  _quote, _______,\
        _______,      _a,      _r,      _s,      _t,      _g, _______,           _______,      _m,      _n,      _e,      _i,      _o, _______,\
        _______,      _z,      _x,      _c,      _d,      _v,                                  _k,      _h,   _comm,    _dot,    _min, _______,\
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,\
                                            _thumbL, _______, _______,           _______, _______, _thumbR )

#include "../../../../rollercole/keymap.c"
#include "rollercole_moonlander_led.c"
