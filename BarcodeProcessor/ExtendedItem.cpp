#include "StdAfx.h"
#include "ExtendedItem.h"
#include "BitLib.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//CExtendedItem::CExtendedItem(EExtendedItemType ItemType) : IItem(ExtendedItem),
//	m_ExtendedItemType((EExtendedItemType)0xFFFFFFFF)
//{
//}

CExtendedItem::~CExtendedItem(void)
{
}

/*virtual*/ void CExtendedItem::InsertItemType()
{
	(GetBitBuffer())[0] = 1;
	(GetBitBuffer())[1] = 1;
	(GetBitBuffer())[2] = 1;
	(GetBitBuffer())[3] = 1;
	(GetBitBuffer())[4] = 1;
}


/*virtual*/ bool CExtendedItem::IsOfThisType(CBitPointer *Data) const
{
	if (*Data[0] != 1) return false;
	if (*Data[1] != 1) return false;
	if (*Data[2] != 1) return false;
	if (*Data[3] != 1) return false;
	if (*Data[4] != 1) return false;
	return true;
}
