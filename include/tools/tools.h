#ifndef _A3_TOOLS_H_
#define _A3_TOOLS_H_

/* use micro to avoid the cast of frequent calls of functions */
#define is_upper(chr) \
    (chr >= 'A' && chr <= 'Z')

#define is_lower(chr) \
    (chr >= 'a' && chr <= 'z')

#define is_alpha(chr) \
    (is_upper(chr) || is_lower(chr))

#define is_digit(chr) \
    (chr >= '0' && chr <= '9') 

#define is_hex_digit(chr) \
    (is_digit(chr) || (chr >= 'a' && chr <= 'f') || (chr >= 'A' && chr <= 'F'))

#define is_oct_digit(chr) \
    (chr >= '0' && chr <= '7')

#define is_bin_digit(chr) \
    (ch == '1' || ch == '0')

#define is_alnum(chr) \
    (is_alpha(chr) || is_digit(chr))

#define to_upper(chr) \
    (is_lower(chr) ? (chr ^ ' ') : chr)

#define is_space(chr) \
    (chr==' '||chr=='\t'||chr=='\r'||chr=='\n'||chr=='\v'||chr=='\f')

#endif
