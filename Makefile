CC			=		clang

ARRC		=		ar rc

RANLIB		=		ranlib

NAME		=		libft.a

DIR_SRC		=		./
DIR_PRINTF	=		./printf/

SRCS_LIB	=		$(DIR_SRC)ft_bzero.c					\
					$(DIR_SRC)ft_memcmp.c					\
					$(DIR_SRC)ft_memcpy.c					\
					$(DIR_SRC)ft_memmove.c					\
					$(DIR_SRC)ft_atoi.c						\
					$(DIR_SRC)ft_memchr.c					\
					$(DIR_SRC)ft_memset.c					\
					$(DIR_SRC)ft_strchr.c					\
					$(DIR_SRC)ft_strcmp.c					\
					$(DIR_SRC)ft_strlen.c					\
					$(DIR_SRC)ft_strncmp.c					\
					$(DIR_SRC)ft_tolower.c					\
					$(DIR_SRC)ft_toupper.c					\
					$(DIR_SRC)ft_strcat.c					\
					$(DIR_SRC)ft_strcpy.c					\
					$(DIR_SRC)ft_strdup.c					\
					$(DIR_SRC)ft_strlcat.c					\
					$(DIR_SRC)ft_strncat.c					\
					$(DIR_SRC)ft_strncpy.c					\
					$(DIR_SRC)ft_strnstr.c					\
					$(DIR_SRC)ft_strstr.c					\
					$(DIR_SRC)ft_isalnum.c					\
					$(DIR_SRC)ft_isalpha.c					\
					$(DIR_SRC)ft_isascii.c					\
					$(DIR_SRC)ft_isdigit.c					\
					$(DIR_SRC)ft_isprint.c					\
					$(DIR_SRC)ft_strrchr.c					\
					$(DIR_SRC)ft_memccpy.c					\
					$(DIR_SRC)ft_memalloc.c					\
					$(DIR_SRC)ft_memdel.c					\
					$(DIR_SRC)ft_strnew.c					\
					$(DIR_SRC)ft_strclr.c					\
					$(DIR_SRC)ft_strdel.c					\
					$(DIR_SRC)ft_striter.c					\
					$(DIR_SRC)ft_striteri.c					\
					$(DIR_SRC)ft_strmap.c					\
					$(DIR_SRC)ft_strmapi.c					\
					$(DIR_SRC)ft_strequ.c					\
					$(DIR_SRC)ft_strnequ.c					\
					$(DIR_SRC)ft_strsub.c					\
					$(DIR_SRC)ft_strjoin.c					\
					$(DIR_SRC)ft_strtrim.c					\
					$(DIR_SRC)ft_strsplit.c					\
					$(DIR_SRC)ft_putchar.c					\
					$(DIR_SRC)ft_putstr.c					\
					$(DIR_SRC)ft_putendl.c					\
					$(DIR_SRC)ft_itoa.c						\
					$(DIR_SRC)ft_putnbr.c					\
					$(DIR_SRC)ft_putchar_fd.c				\
					$(DIR_SRC)ft_putstr_fd.c				\
					$(DIR_SRC)ft_putendl_fd.c				\
					$(DIR_SRC)ft_putnbr_fd.c				\
					$(DIR_SRC)ft_lstdelone.c				\
					$(DIR_SRC)ft_lstnew.c					\
					$(DIR_SRC)ft_lstdel.c					\
					$(DIR_SRC)ft_lstadd.c					\
					$(DIR_SRC)ft_lstiter.c					\
					$(DIR_SRC)ft_lstmap.c					\
					$(DIR_SRC)ft_realloc.c					\
					$(DIR_SRC)ft_lstaddend.c				\
					$(DIR_SRC)ft_countiter.c				\
					$(DIR_SRC)ft_lstsize.c					\
					$(DIR_SRC)ft_lstat.c					\
					$(DIR_SRC)ft_lstfreeone.c				\
					$(DIR_SRC)ft_putwchar.c					\
					$(DIR_SRC)ft_putwstr.c					\
					$(DIR_SRC)get_next_line.c				\
					$(DIR_SRC)ft_error.c					\
					$(DIR_PRINTF)ft_printf.c						\
					$(DIR_PRINTF)utils/parse.c						\
					$(DIR_PRINTF)utils/buff_list.c					\
					$(DIR_PRINTF)utils/free_fcts.c					\
					$(DIR_PRINTF)utils/string_magic.c				\
					$(DIR_PRINTF)utils/flag_detectors.c				\
					$(DIR_PRINTF)utils/flag_handelers.c				\
					$(DIR_PRINTF)managers/custom_putstr.c			\
					$(DIR_PRINTF)utils/chunk_normaliser.c			\
					$(DIR_PRINTF)managers/custom_putchar.c			\
					$(DIR_PRINTF)managers/manage_padding.c			\
					$(DIR_PRINTF)managers/prefix_manager.c			\
					$(DIR_PRINTF)managers/hashtag_manager.c			\
					$(DIR_PRINTF)managers/precision_manager.c		\
					$(DIR_PRINTF)managers/custom_putnbr_signed.c	\
					$(DIR_PRINTF)managers/custom_putnbr_unsigned.c	\
					$(DIR_PRINTF)utils/generator.c					\
					$(DIR_PRINTF)utils/psf_init.c					\
					$(DIR_PRINTF)utils/putstr_lst.c					\
					$(DIR_PRINTF)utils/var_loaders.c				\
					$(DIR_PRINTF)utils/check_zero.c					\
					$(DIR_PRINTF)utils/var_loaders_2.c				\
					$(DIR_PRINTF)managers/scotch.c					\
					$(DIR_PRINTF)managers/w_precision.c				\
					$(DIR_PRINTF)managers/w_convertor.c				\
					$(DIR_PRINTF)managers/wgen.c					\
					$(DIR_PRINTF)utils/var_loaders_unsigned_2.c		\
					$(DIR_PRINTF)utils/var_loaders_unsigned.c

OBJS_LIB	=		$(SRCS_LIB:.c=.o)

CFLAGS		+=		-I./
CFLAGS		+=		-Wall -Wextra -Werror

RM			=		rm -f

ECHO		=		printf

.PHONY		:		clean

all			:		$(NAME)

$(NAME)	:			$(OBJS_LIB)
					@$(ECHO) "\033[35m[~~~~~ CREATION LIB ~~~~~~~~]  \033[0m"
					@$(ARRC) $(NAME) $(OBJS_LIB) && $(ECHO) "\033[32m[OK]\n\033[0m" || @$(ECHO) "\033[31m[KO]\n\033[0m"
					@$(ECHO) "\033[35m[~~~~~ RANLIB ~~~~~~~~~~~~~~]  \033[0m"
					@$(RANLIB) $(NAME) && $(ECHO) "\033[32m[OK]\n\033[0m" ||@$(ECHO) "\033[31m[KO]\n\033[0m"
					@$(ECHO) "\033[33m[~~~~~ LIB OK ~~~~~~~~~~~~~~]  [OK]\n\033[0m"

%.o			:		%.c
					@$(ECHO) "\033[36m[~~~~~ COMPILATION OBJ ~~~~~]  \033[0m"
					@$(CC) $(CFLAGS) -o $@ -c $< && $(ECHO) "\033[33;32m["$@"] \n\033[0m" || $(ECHO) "\033[31m["$@"] \n\033[0m"

clean		:
					@$(RM) $(OBJS_LIB) && $(ECHO) "\033[31m[~~~~~ SUPRESSION .O LIB ~~~]  [OK]\n\033[0m"

fclean		:		clean
					@$(RM) $(NAME) && $(ECHO) "\033[31m[~~~~~ SUPRESSION LIB ~~~~~~]  [OK]\n\033[0m"

fc_distant	:
					@$(RM) $(NAME) && $(ECHO) "\033[31m[~~~~~ SUPRESSION LIB ~~~~~~]  [OK]\n\033[0m"
	

re			:		fclean all

