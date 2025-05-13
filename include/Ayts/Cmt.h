#ifndef Ayts_Cmt_h

#include <stddef.h>
#include <stdint.h>

/**
 * @brief
 * The raw data group
 * */
typedef struct Ayts_mCmt {
  /** @brief Username (or handle) */
  const char *m_name;
  /** @brief Comment contents */
  const char *m_txt;
  /** @brief Profile picture */
  const uint8_t *m_profile;
} Ayts_mCmt;

/**
 * @brief
 * The crawled data group which contains
 * */
typedef struct Ayts_mCmtX {
  uint8_t Unused[sizeof(Ayts_mCmt)];
  /** @brief sizeof(m_kinder) */
  size_t m_kinder_sz;
  /** @brief Following contents */
  const Ayts_mCmt *m_kinder;
} Ayts_mCmtX;

typedef union Ayts_Cmt {
  Ayts_mCmt mCmt;
};

typedef union Ayts_CmtX {
  Ayts_mCmt mCmt;
  Ayts_mCmtX mCmtX;
};

#endif
