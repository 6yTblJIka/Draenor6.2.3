////////////////////////////////////////////////////////////////////////////////
//
// Project-Hellscream https://hellscream.org
// Copyright (C) 2018-2020 Project-Hellscream-6.2
// Discord https://discord.gg/CWCF3C9
//
////////////////////////////////////////////////////////////////////////////////

#include "SHA256.h"
#include "BigNumber.h"
#include <stdarg.h>

SHA256Hash::SHA256Hash()
{
    SHA256_Init(&mC);
    memset(mDigest, 0, SHA256_DIGEST_LENGTH * sizeof(uint8));
}

SHA256Hash::~SHA256Hash()
{
    SHA256_Init(&mC);
}

void SHA256Hash::UpdateData(const uint8 *dta, int len)
{
    SHA256_Update(&mC, dta, len);
}

void SHA256Hash::UpdateData(const std::string &str)
{
    UpdateData((uint8 const*)str.c_str(), str.length());
}

void SHA256Hash::UpdateBigNumbers(BigNumber* bn0, ...)
{
    va_list v;
    BigNumber* bn;

    va_start(v, bn0);
    bn = bn0;
    while (bn)
    {
        UpdateData(bn->AsByteArray(), bn->GetNumBytes()); // this might not good :S old was: UpdateData(bn->AsByteArray().get(), bn->GetNumBytes());
        bn = va_arg(v, BigNumber*);
    }
    va_end(v);
}

void SHA256Hash::Initialize()
{
    SHA256_Init(&mC);
}

void SHA256Hash::Finalize(void)
{
    SHA256_Final(mDigest, &mC);
}

