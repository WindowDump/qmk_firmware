# Quantum Mechanical Keyboard Firmware

This is a fork of the official QMK firmware. For documentation and build information, please visit [the main GitHub repository](https://github.com/qmk/qmk_firmware/), the official website [qmk.fm](https://qmk.fm), or [see the official documentation on docs.qmk.fm](https://docs.qmk.fm).

# My Keymaps

This is what you're actually here for.

## Corne Choc (No OLED's)

``crkbd:dumpspec``

Baby's first 40% board. Desperate flailing to move all the keys to where I can get at them.

## Lily58 Pro (Mystic Mech Spec) "Lily White"

``lily58:dumpspec``

Comes with two OLED screens and a rotary encoder on the left half. I did not get the encoder talking over TRRS yet. I also put in choc sockets and two Elite-C's because I am bad at spending money. Get standoffs in varrying sizes ahead of time if you plan to do this.

Very heavily based on my Iris keymap, since the two are almost the same layout. I don't know what to do with the extra keys. I made this fork because the PR to update the OLED to the new API hadn't been pulled and I want to display dumb images on my OLED's to impress people that don't know the difference between Gateron and Kailh.

I've slammed in the code to make this use the new common split keyboard code. Currently trying to jam in custom rendering code that doesn't break. It's surprisingly hard and I don't know why. Please, oled_write_raw_P, don't lock up the display.

The unofficial keyboard of Phanasmagoria Netplay. PoFV 2020.

This keyboard is Reddit Famous. Spin the encoder for updoots, my dude.

## Iris Rev. 4 (Dual Encoders) "Steel Iris"

``keebio/iris/rev4:dumpspec``

Taking inspiration from the default keymap and my Ortho60 keymap, I found a wonderful balance that let me put the matthewrobo nav cluster in an easy to reach position along with a numpad where I needed it, and I hacked in another layer for STG's [because some drunk Japanese dude didn't feel like letting me remap keys](https://twitter.com/zun_code) and I didn't want to make an AHK script. I had trouble trying to figure out what to do with the rotary encoders, but they look cool.

## Ortho60 (Full Grid) "Immortal Smoke"

``cannonkeys/ortho60:dumpspec``

Tweaked the default keymap somewhat to add in the matthewrobo nav cluster on Ctrl and some other things I'm forgetting at the moment. Non-split ortho hurts my wrists. Big thing is putting backspace on left outer thumb key, and a GAMER mode to overwrite it.

## DZ65RGB "Ordinary Keyboard"

``dztech/dz65rgb:dumpspec``

Very heavily based on the awesome ``matthewrobo`` keymap which has all kinds of cool LED effects for active layers and adjusting things on the fly. Highlights are the nav cluster on Caps Lock, autoshift, and a Colemak layer so I can flex on Reddit. I did a few tweaks here and there to get used to QMK.
