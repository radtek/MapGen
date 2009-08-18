#include "StdAfx.h"
#include "GeneralHeader.h"
#include "BitLib.h"

CGeneralHeader::CGeneralHeader(void) : m_Signature(ConvertIntToInt32Bit(0)), 
	m_Version(ConvertIntToInt4Bit(0)), m_BarcodeType((EBarcodeType)0)
{
}

CGeneralHeader::~CGeneralHeader(void)
{
}


void CGeneralHeader::Encode(Int32Bit Signature, Int4Bit Version, EBarcodeType BarcodeType)
{
	size_t NumberOfBits	= BitSize(Signature) 
		+ BitSize(Version) 
		+ BitSize(BarcodeType);
	IncreaseBitBufferSize(NumberOfBits);

	CBitPointer BitPtr = AllocateBitBuffer();
	BitCopyAndContinue(BitPtr, Signature);
	BitCopyAndContinue(BitPtr, Version);
	BitCopyAndContinue(BitPtr, BarcodeType);
}

void CGeneralHeader::Decode(IN const CBitPointer &Data, IN OUT int &UsedBits)
{
	int BitsToRead = UsedBits; BitsToRead;
	CBitPointer BitPtr = Data;

	BitPasteAndContinue(BitPtr, m_Signature);
	BitPasteAndContinue(BitPtr, m_Version);
	BitPasteAndContinue(BitPtr, m_BarcodeType);
	
	UsedBits = (int)(BitPtr - Data);
}