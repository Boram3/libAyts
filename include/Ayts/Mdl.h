#ifndef Ayts_Mdl_h
#define Ayts_Mdl_h

#define MDL_FLAG_DONT 0b00
#define MDL_FLAG_SEXUAL 0b01
#define MDL_FLAG_SUSPICIOUS 0b10

#include <stdbool.h>
#include <stdint.h>

/** @brief
 * Raw flag type. [Unsigned 8-bit integer]
 *
 *
 * */
typedef uint8_t MdlFlag_t;

/** @brief None */
#define MDL_FLAG_DONT 0b00

/** @brief  */
#define MDL_FLAG_SEXUAL 0b01
#define MDL_FLAG_SUSPICIOUS 0b10

/**
 * @brief
 * Output selection flag for model.
 * */
typedef union Ayts_MdlFlag {
  /** @brief The final byte to be used on API. */
  MdlFlag_t m_byte;

  /** @brief Field selection helper */
  struct {
    bool m_sexual : 1;
    bool m_suspicious : 1;
  } m_field;
} Ayts_MdlFlag;

#endif
