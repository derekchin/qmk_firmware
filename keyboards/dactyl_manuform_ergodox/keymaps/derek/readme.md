#dactyl_manuform_ergodox layout
Alexander (Sasha) Karmanov, 20170901

This is a layout for the Dactyl-ManuForm cross-breed keyboard which @TShort combined
from the Dactyl keyboard created by Matt Aderetha and @Jeffgran's ManuForm keyboard.

https://geekhack.org/index.php?topic=88576.0

Also I got some ideas from Ergodox EZ default mapping, namely the combination of the cursor
and mouse cotrol in a single layer.

For this layout I added the ideas from Space-FN layout implemented in TouchCursor app
and many similar AHK scrips, including the one-hand typing layouts like FrogPad
and Matias single-hand keyboards.

All that was tried first on a split Planck keyboard I made following these instructions:
https://clintgeek.wordpress.com/2017/06/04/lets-split-planck-hard-mode/
Then I used the same layout on a Let's Split and finally it came to this Dactyl-Manuform.

These were my considerations:
- as few hand movements from the home position as possible
  I.e.the fingers to stay in the home row/home position most of the time.
  The reduced number of rows and columns in Planck, Let's Split and Dactyl-Manuform
  enforce it naturally.
- no akward finger placement in multi-key combinations
  That is the fingers should be not reaching in different directions,
  e.g. Win+E pressed by left ring and middle fingers going respectively down and up.
  For that a repeated key to be on he other side 	
- as close to QWERTY as possible - I do not want to re-learn the touchtyping again.
- as close to the standard numbers, FN locations as possible
- the modifiers remain in the usual places or at least in the same order
  (mind I used Thinkpad keyboards for 15+ years, so I biased to they way they were laid out)
- Space to be in the usual location and be wide enough, i.e. not restricted to a single key.
- no permanent layer switching except for the Plover and Numpad,
  instead the idea of Raise and Lower layers is used.
- keep the rightmost side of the standard keyboard available in a closer form.
  (That is needed primarily for the Russian layout as defined for the standard Qwerty keyboard,
  all those extra symbols are put on the brackets, slash, and other non-alphanumerical keys.
  I do not want to re-learn touchtyping in that language either.)
- the navigation controls should be easy to use for the text/code editing
  since I do that for a few hours a day. 
- the navigation with cursor to be done with one hand, either of them.
  Being able to do the editig is nice but not really required.
- A few special keys/combinations to be easily reached - Ctrl+Break; ~ sign;
  Shift+, Ctrl+ and Alt+numbers and FNs; combinations of Shift, Ctrl and Alt and any other key(s).
  Need that for FAR manager and some IDEs.
- Ctrl to be pressed with the palm (just the habit I got with the split Planck)
- Enter to be present on both halves, with a modifier on the left side.
  Put it on Tab in the cursor key layers.
- Keep the nature of the key similar in all layers.
  I.e. Backspace becomes Del but not Escape or Enter.
- Avoid using the alphanumeric key as modifiers.
  While it seemed promising in Ergodox I noticed a significant lag and misfiring 
  on those keys, just plainly annoing, do not want to bother with that anymore.
- Mouse to be controlled with the keyboard as comfortable as possible.
  From one hand a Touch Stick could be added, but from other hand it was a bit too much 
  for me to work on, may be in a later version I will add one.
- Cut/Copy/Paste/Undo operations to be performed with modifiers other than Ctrl.
  That is the Ctrl keys are placed much closer to ZXCV on the left, 
  have to twist my wrist a lot more compared to the same movements with Thinkpad's board.
- Thumb cluster keys to be immutable, thumbs are quite hard to re-train.

So those ideas led me to the following layers:

1. Basic QWERTY and modifiers.
   Modifiers are projected into other layers.
   
2. Cursor keys on the right (IJKL), Mouse on the left (ESDF), 
   Home/End/PgUp/PgDn on the right, Cut-Copy-Paste and Mouse buttons on the left.
   Turned momentarily on by a key pressed by the right thumb.

3. Cursor keys on the left (ESDF), Mouse on the right (IJKL), 
   Home/End/PgUp/PgDn on the left, Cut-Copy-Paste and Mouse buttons on the right.
   Turned momentarily on by a key pressed by the left thumb

4. Numbers, FN layer turned on by pressing two keys by the left and right thumbs.
   Numbers on the top row, FNs on the second, FN11 and FN12 in the left bottom corner. 

5. Extended right side, i.e. those non-alphanumeric keys from the right side of ANSI keyboards.
   shifted to the left into the existing keys.
   Turned on momentarily by holding Tab.

6. Numpad layer with the numbers on the right side as in a numeric keypad, plus the top row is the numbers
  This layer can be turned on permanently by a combination similar to NumLock.

7. Plover layer, also can be turned on permanently by another combination, 
   it turned off back into QWERTY.

Most of the time I use layers 1-5.
Numpad layer #6 I thought would be used, but in reality I turned it on a few times by accident only.
Plover layout #7 I only started to learn, so it also is barely used compared to ##s 1-5.

All momentarily swithed layers got additional Alt and Shift keys under the index fingers,
thus one simplifying the combos in those layers.

In Planck and Let's Split I used the bottom innermost keys as layer switchers for #2 and #3.
Next ones were for Alt.
In Dactyl it is a bit different, also it has only 3 rows in the outermost columns,
so Shift was moved to the thumb cluster.
Now the thumbs rest on the layer #2 and #3 switchers, arc inside for Shift, and outside for Ctrl.
Alts are under middle fingers in the bottom row, also there is another pair of Alts in 
the thumb cluster. 
The left ring finger gets Win key in the bottom row, and the right one used for the system menu.
This way the thumbs move in an arc over the top inner corner of the thumb clusters,
rarely reaching for other keys.

This layout proved to be quite comfortable, I used it for the last four-five months already.

In the layers below the empty cells represent transparent keys.
XXXs and '...'s are the blocked keys, not passing the key press to the lower layer.
Need them to avoid unexpected symbols to appear or actions to be invoked.
Lower rows of the thumb clusters are not shown when they are transparent,
just to have them compact enough to fit in a page.

/* Keymap 0: Basic layer
 * ,-------------------------------------------.           ,-----------------------------------------.
 * | Esc    |   Q  |   W  |   E  |   R  |   T  |           |  Y  |   U  |   I  |   O  |   P  | BkSpc |
 * |--------+------+------+------+------+------|           |-----+------+------+------+------+-------|
 * |Tab/ExRt|   A  |   S  |   D  |   F  |   G  |           |  H  |   J  |   K  |   L  |   ;  | Enter |
 * |--------+------+------+------+------+------|           |-----+------+------+------+------+-------|
 * | LCtrl  |   Z  |   X  |   C  |   V  |   B  |           |  N  |   M  |   ,  |   .  |   /  | RCtrl |
 * `--------+------+------+------+------+------'           `-----+------+------+------+------+-------'
 *                 |  Win | Alt  |                                      | AltGr| Menu |
 *                 `-------------'                                      `-------------'
 *                                 ,-------------.         ,-------------.
 *                                 |LShift| CCLt |         | CCRt |RShift|
 *                                 |    Space    |         |    Space    |
 *                                 ,------|------|         |------+------|
 *                                 |LAlt  |LCtrl |         | RCtrl|RAlt  | 
 *                                 |    Space    |         |   Space     |
 *                                 ,------|------|         |------+------|
 *                                 | GUI  |ExtRt |         |Menu  | GUI  | 
 *                                 |      |      |         |      |      |
 *                                 `-------------'         `-------------'
 */


/* Keymap 1: CURSORRGHT - cursor on the right, mouse on the left
 * X marks modifier turning this layer on
 * Thumb cluster's bottom part is not shown - it is transparent in this layer.
 * ,-------------------------------------------.           ,------------------------------------------.
 * |        |Break |WheelD|MousUp|WheelU| Del  |           |  Ins | Home |  Up  | End  |   `  | Del   |
 * |--------+------+------+------+------+------|           |------+------+------+------+------+-------|
 * | Enter  |SelAll|MousLt|MousDn|MousRt|  ... |           | PgUp | Left | Down |Right |  ... |       |
 * |--------+------+------+------+------+------|           |------+------+------+------+------+-------|
 * |        | Undo | Cut  | Copy | Paste|RShift|           | PgDn |MsBtLe|MsBtMi|MsBtRt|  ... |       |
 * `--------+------+------+------+------+------'           `------+------+------+------+------+-------'
 *                 |ExtRt | GUI  |                                       | Space| Menu | 
 *                 `-------------'                                       `-------------'
 *                                 ,-------------.         ,-------------.
 *                                 |      |      |         |   X  |      |
 */

/* Keymap 2: CURSORLEFT - cursor on the left, mouse on the right
 * X marks modifier turning this layer on
 * Thumb cluster's bottom part is not shown - it is transparent in this layer.
 * ,-------------------------------------------.           ,------------------------------------------.
 * |        |Break | Home |  Up  | End  |  Ins |           | Del  |WheelU|MousUp|WheelD|   `  | Del   |
 * |--------+------+------+------+------+------|           |-------------+------+------+------+-------|
 * | Enter  |SelAll|Right | Down | Left | PgUp |           |  xxx |MousLt|MousDn|MousRt| xxx  |       |
 * |--------+------+------+------+------+------|           |------|------+------+------+------+-------|
 * |        |      |MsBtRt|MsBtMi|MsBtLe| PgDn |           |RShift| Cut  | Copy | Paste| xxx  |       |
 * `--------+------+------+------+------+------'           `------+------+------+------+------+-------'
 *                 |ExtRt | GUI  |                                       | Space| Menu | 
 *                 `-------------'                                       `-------------'
 *                                 ,-------------.         ,-------------.
 *                                 |      |   X  |         |      |      |
 */
/* Keymap 3: NUMBERS - numbers and F-keys
 * X1, X2 are modifiers turning this layer on
 * Thumb cluster's bottom part is not shown - it is transparent in this layer.
 * ,-------------------------------------------.           ,------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  | Del   |
 * |--------+------+------+------+------+------|           |------+------+------+------+------+-------|
 * |        |   F1 |   F2 |   F3 |   F4 |   F5 |           |   F6 |   F7 |   F8 |   F9 |   F10|       |
 * |--------+------+------+------+------+------|           |------+------+------+------+------+-------|
 * |        |  F11 |  F12 |LCtrl |LShift| LAlt |           | RAlt |RShift|   ,  |   .  |   /  |       |
 * `--------+------+------+------+------+------'           `------+------+------+------+------+-------'
 *                 |      |      |                                |      |      | 
 *                 `-------------'                                `-------------'
 *                                 ,-------------.         ,-------------.
 *                                 |      |  X1  |         |   X2 |      |
 */

/* Keymap 4: NUMBERPAD - numpad on the right along with the arithetic operations
 * Thumb cluster is not shown - it is transparent in this layer.
 * ,-------------------------------------------.           ,------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  | Del    |
 * |--------+------+------+------+------+------|           |------+------+------+------+------+--------|
 * |        | ...  | ...  | ...  | ...  | ...  |           |   +  |   4  |   5  |   6  |   *  |        |
 * |--------+------+------+------+------+------|           |------+------+------+------+------+--------|
 * |        | ...  | ...  | ...  |LShift| LAlt |           | RAlt |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+------'           `------+------+------+------+------+--------'
 *                 |      |      |                                |   0  |   -  |
 *                 `-------------'                                `-------------'
 */

/* Keymap 5: EXTRARIGHT // far-right side keys shifted onto the existing keys
 * Thumb cluster is not shown - it is transparent in this layer.
 * X marks modifier turning this layer on
 * ,-------------------------------------------.           ,------------------------------------------.
 * |        |   `  |  ... |  ... |  ... |  ... |           |   `  |   (  |   )  |   -  |   =  | Del    |
 * |--------+------+------+------+------+------|           |------+------+------+------+------+--------|
 * |    X   |CAPSLK|NUMPAD|PLOVER|  ... |  ... |           | ...  | ...  | ...  | ...  |  '   |        |
 * |--------+------+------+------+------+------|           |------+------+------+------+------+--------|
 * |   Shift|  ... |  ... |  ... | LShft| LAlt |           | RAlt | RShft|   [  |   ]  |  \   |        |
 * `--------+------+------+------+------+------'           `------+------+------+------+------+--------'
 *                 |      |      |                                |      |      | 
 *                 `-------------'                                `-------------'
 */
 
Plover layout is not shown here, see keymap.c file for that layout.

Notes on the layouts:
- ExtraRight layer is on top of the others so I can have both thumbs holding the numbers layer,
  then adding the parenthesis and dash and other symbols from that right side part.
