// ┌─────────────────────────────────────────────────┐
// │ t a p p i n g t e r m                           │
// └─────────────────────────────────────────────────┘

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_X:
        case GUI_DOT:
        case ALT_C:
        case ALT_COMM:
            return TAPPING_TERM + 50;
        case CTL_Z:
        case CTL_SLSH:
            return TAPPING_TERM + 50;
        case SHT_F:
        case SHT_J:
            return TAPPING_TERM - 20;
        default:
            return TAPPING_TERM;
    }
}
#endif

#ifdef QUICK_TAP_TERM_PER_KEY
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SHT_J:
            return QUICK_TAP_TERM + 70;
        default:
            return QUICK_TAP_TERM;
    }
}
#endif

#ifdef RETRO_TAPPING_PER_KEY
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_X:
            return true;
        default:
            return false;
    }
}
#endif
