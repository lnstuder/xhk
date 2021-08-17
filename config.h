


// Locales --------------------

#pragma region
/* Available Locales
-------------------------------
#define XK_MISCELLANY
#define XK_XKB_KEYS
#define XK_XFREE86
#define XK_LATIN1
#define XK_LATIN2
#define XK_LATIN3
#define XK_LATIN4
#define XK_LATIN8
#define XK_LATIN9
#define XK_CAUCASUS
#define XK_GREEK
#define XK_KATAKANA
#define XK_ARABIC
#define XK_CYRILLIC
#define XK_HEBREW
#define XK_THAI
#define XK_KOREAN
#define XK_ARMENIAN
#define XK_GEORGIAN
#define XK_VIETNAMESE
#define XK_CURRENCY
#define XK_MATHEMATICAL
#define XK_BRAILLE
#define XK_SINHALA
*/
#pragma endregion

#define XK_LATIN1
#define XK_MISCELLANY
#define XK_XKB_KEYS
// ----------------------------

// Routine Definitions
void open_terminal() {
    printf("Opening terminal...");
}

#include <X11/keysymdef.h>
// Hotkeys Atlas
static const hotkey_t hotkeys[1] = {
    {XCB_MOD_MASK_CONTROL|XCB_MOD_MASK_SHIFT, XK_Return, XCB_KEY_PRESS, &open_terminal}
};
