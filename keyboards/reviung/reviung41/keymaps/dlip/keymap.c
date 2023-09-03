/* Copyright 2020 gtips
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "dlip.h"

enum layer_names {
    _BASE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
       _______, TP_TLP,        TP_TLR,    TP_TLM,       TP_TLI, _______,          _______, TP_TRI,     TP_TRM,     TP_TRR,     TP_TRP, XXXXXXX,
       _______, TP_BLP,        TP_BLR,    TP_BLM,       TP_BLI, _______,         _______, TP_BRI,     TP_BRM,     TP_BRR,     TP_BRP, XXXXXXX,
       _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
                                 TP_LIT,       TP_LOT, _______,         TP_ROT,     TP_RIT
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (IS_LAYER_ON(_BASE)) {
        return taipo_process_record_user(keycode, record);
    }  else {
        return true;
    }
};

void matrix_scan_user(void) {
    taipo_matrix_scan_user();
}


