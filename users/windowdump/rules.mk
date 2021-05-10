SRC += windowdump.c

EXTRAKEY_ENABLE       = yes
MOUSEKEY_ENABLE       = yes
NKRO_ENABLE           = yes
CONSOLE_ENABLE = no

ifneq ($(PLATFORM),CHIBIOS)
    LTO_ENABLE        = yes
endif
SPACE_CADET_ENABLE    = no
GRAVE_ESC_ENABLE      = no

ifeq ($(strip $(QUICK_SWITCH)), yes)
    OPT_DEFS += -DQUICK_SWITCH
endif
