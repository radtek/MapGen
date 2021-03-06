#include "StdAfx.h"
#include "ItemStructure.h"
#include "BitLib.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CItemStructure::CItemStructure(void) : IItem(SubItem)
{

}

CItemStructure::~CItemStructure(void)
{

}

void CItemStructure::Encode(SStructureShape StructureShape, SMultiplicity Multiplicity)
{
	size_t NumberOfBits	= BitSize(StructureShape) 
						+ BitSize(Multiplicity);
	
	IncreaseBitBufferSize(NumberOfBits);

	CBitPointer BitPtr = AllocateBitBuffer();

	BitCopyAndContinue(BitPtr, Multiplicity.IsMultiplied);
	
	if (Multiplicity.IsMultiplied)
		BitCopyAndContinue(BitPtr, Multiplicity.Multiples);

	BitCopyAndContinue(BitPtr, StructureShape.AngleType);
	switch (StructureShape.AngleType)
	{
	case SStructureShape::None:
		break;
	case SStructureShape::AngleUpTo90:
		BitCopyAndContinue(BitPtr, StructureShape.Shape.SmallAngle);
		break;
	case SStructureShape::AngleUpTo360:
		BitCopyAndContinue(BitPtr, StructureShape.Shape.BigAngle);
		break;
	case SStructureShape::Circular:
		BitCopyAndContinue(BitPtr, StructureShape.Shape.RadiusCoordinates.X);
		BitCopyAndContinue(BitPtr, StructureShape.Shape.RadiusCoordinates.Y);
		break;
	};
}

/*virtual */void CItemStructure::Decode(IN const CBitPointer &Data, IN OUT int &UsedBits, IN int* /*Context unnecessary*/)
{
	int BitsToRead = UsedBits; BitsToRead;
	CBitPointer BitPtr = Data + BitSize(GetType());


	BitPasteAndContinue(BitPtr, m_Multiplicity.IsMultiplied);

	if (m_Multiplicity.IsMultiplied)
		BitPasteAndContinue(BitPtr, m_Multiplicity.Multiples);

	BitPasteAndContinue(BitPtr, m_StructureShape.AngleType);
	switch (m_StructureShape.AngleType)
	{
	case SStructureShape::None:
		break;
	case SStructureShape::AngleUpTo90:
		BitPasteAndContinue(BitPtr, m_StructureShape.Shape.SmallAngle);
		break;
	case SStructureShape::AngleUpTo360:
		BitPasteAndContinue(BitPtr, m_StructureShape.Shape.BigAngle);
		break;
	case SStructureShape::Circular:
		BitPasteAndContinue(BitPtr, m_StructureShape.Shape.RadiusCoordinates.X);
		BitPasteAndContinue(BitPtr, m_StructureShape.Shape.RadiusCoordinates.Y);
		break;
	};

	UsedBits = (int)(BitPtr - Data);
}


/*virtual*/	std::string	CItemStructure::GetItemBitBufferParsedString(std::string ParsedString, CBitPointer BitPtr)
{

	AddItemToBitString(m_Multiplicity.IsMultiplied, BitPtr, ParsedString);
	
	if (m_Multiplicity.IsMultiplied)
		AddItemToBitString(m_Multiplicity.Multiples, BitPtr, ParsedString);

	AddItemToBitString(m_StructureShape.AngleType, BitPtr, ParsedString);
	switch (m_StructureShape.AngleType)
	{
	case SStructureShape::None:
		break;
	case SStructureShape::AngleUpTo90:
		AddItemToBitString(m_StructureShape.Shape.SmallAngle, BitPtr, ParsedString);
		break;
	case SStructureShape::AngleUpTo360:
		AddItemToBitString(m_StructureShape.Shape.BigAngle, BitPtr, ParsedString);
		break;
	case SStructureShape::Circular:
		AddItemToBitString(m_StructureShape.Shape.RadiusCoordinates.X, BitPtr, ParsedString);
		AddItemToBitString(m_StructureShape.Shape.RadiusCoordinates.Y, BitPtr, ParsedString);
		break;
	};

	return ParsedString;
}