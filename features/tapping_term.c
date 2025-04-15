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
            return TAPPING_TERM + 80;
        case CTL_Z:
        case CTL_SLSH:
            return TAPPING_TERM + 50;
        case SHT_F:
        case SHT_J:
            return TAPPING_TERM + 30;
        default:
            return TAPPING_TERM;
    }
}
#endif
