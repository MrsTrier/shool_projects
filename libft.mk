L_FT    ?= .
FT_NAME    := libftprintf.a
NAME    := FT_NAME
FT_LNK    := -L $(L_FT) -l ft
FT_INC    := -I $(L_FT)/include
FT_LIB    := $(L_FT)/$(FT_NAME)
# Global variables for compilation
ifndef LIB_LNK
LIB_LNK    :=
LIB_INC    :=
endif
LIB_LNK    += $(FT_LNK)
LIB_INC    += $(FT_INC)