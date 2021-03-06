#pragma once

static const int MaxNumberOfArgumentsPerLine	= 64;
static const int MaxNumberOfLinesPerCommand		= 64;
static const char *CommandDelimiter			= ":";
static const char *ArgumentsDelimiter		= "|";
static const char *ListItemsDelimeter		= " ";
static const char *ListBegin				= "{";
static const char *ListEnd					= "}";
static const char *StructFieldsDelimeter	= ",";
static const char *StructBegin				= "[";
static const char *StructEnd				= "]";
static const char *CommandEnd				= ";";
static const char *ParemterNameFromValueSeperator = "=";
static const char *EndOfScript				= "End";
static const char *CommentMark				= "%";

#define ArgumentNameOf(x) #x
static const char *StrVectorDelimiter = ", ";		// note: this is not part of the script language but is the separator between 
// enum values in the enum lists defined below:


// Explanation about Syntax:
// Each parameter is defined as a list, separated by comma+space (", ")
// First item in list is the Parameter name as it appears in the script
// Second item in list is the Parameter type (enum, struct, union, Int8Bit, Int4Bit, char, bool, etc..
// If Item is either struct, enum or union, there will be more parameters, indicating:
// In enum: the possible values, ORDERED as the enum itself (according value)
// In struct: the name of the fields, ORDERED as expected to be filled by the user
// In union: the name of the fields



// GeneralHeader Syntax:
// ---------------
static const char *GeneralHeaderCommand = "GeneralHeader";

static const std::string Signature			= "Signature, Int32Bit";
static const std::string Version			= "Version, Int4Bit";
static const std::string BarcodeType		= "BarcodeType, enum, ParkingMap";


// ParkingMapHeader Syntax:
// ---------------
static const char *ParkingMapHeaderCommand = "ParkingMapHeader";

static const std::string TextLanguage						= "TextLanguage, enum, English, Hebrew";

static const std::string ParkingGarageID					= "ParkingGarageID, struct, A, B, C, D";
static const std::string ParkingGarageID_A					= "A, Int8Bit";
static const std::string ParkingGarageID_B					= "B, Int8Bit";
static const std::string ParkingGarageID_C					= "C, Int8Bit";
static const std::string ParkingGarageID_D					= "D, Int8Bit";

static const std::string ParkingGarageDimensions			= "ParkingGarageDimensions, struct, Height, Width";
static const std::string ParkingGarageDimensions_Height		= "Height, Int16Bit";
static const std::string ParkingGarageDimensions_Width		= "Width, Int16Bit";

static const std::string ParkingSpaceDimensions				= "ParkingSpaceDimensions, struct, Height, Width";
static const std::string ParkingSpaceDimensions_Height		= "Height, Int8Bit";
static const std::string ParkingSpaceDimensions_Width		= "Width, Int8Bit";

static const std::string FloorAndSection				= "FloorAndSection, struct, Floor, Section";
static const std::string FloorAndSection_Floor			= "Floor, Int4Bit";
static const std::string FloorAndSection_Section		= "Section, Int4Bit";

static const std::string CurrentPosition				= "CurrentPosition, struct, X, Y";
static const std::string CurrentPosition_X				= "X, Int8Bit";
static const std::string CurrentPosition_Y				= "Y, Int8Bit";

static const std::string IsTargetPosition				= "IsTargetPosition, bool";
static const std::string IsTargetDescription			= "IsTargetDescription, bool";
//static const std::string TargetDescription			= "TargetDescription, char";
static const std::string TargetPosition					= "TargetPosition, struct, X, Y";
static const std::string TargetPosition_X				= "X, Int8Bit";
static const std::string TargetPosition_Y				= "Y, Int8Bit";


// Parking Syntax:
// ---------------
static const char *ParkingCommand = "Parking";

static const std::string ParkingAngle			= "Angle, enum, Perpendicular, Parallel, Right45Degrees, Left45Degrees";
static const std::string ParkingType			= "Type, enum, Regular, Handicap, Bikes, BigParking";
static const std::string IsMirrorDoubled		= "IsMirrorDoubled, bool";
static const std::string IsWallBetweenMirrors 	= "IsWallBetweenMirrors, bool";
static const std::string Orientation			= "Orientation, enum, Degrees0, Degrees90, Degrees180, Degrees270";
static const std::string IsPeriodicBetweenPoles = "IsPeriodicBetweenPoles, bool";

static const std::string PeriodicBetweenPoles						= "PeriodicBetweenPoles, struct, NumberOfParkingPlaces, PolesType";
static const std::string PeriodicBetweenPoles_NumberOfParkingPlaces = "NumberOfParkingPlaces, Int4Bit";
static const std::string PeriodicBetweenPoles_PolesType				= "PolesType, enum, Pavement, Circular, Squared, Wall, EPolesType_MaxEnum";

static const std::string Multiplicity						= "Multiplicity, struct, IsMultiplied, Multiples";
static const std::string Multiplicity_IsMultiplied			= "IsMultiplied, bool";
static const std::string Multiplicity_Multiples				= "Multiples, Int6Bit";

static const std::string StructureShape								= "StructureShape, struct, AngleType, Shape";
static const std::string StructureShape_AngleType					= "AngleType, enum, None, AngleUpTo90, AngleUpTo360, Circular";
static const std::string StructureShape_Shape						= "Shape, union, SmallAngle, BigAngle, RadiusCoordinates";
static const std::string StructureShape_Shape_SmallAngle			= "SmallAngle, Int6Bit";
static const std::string StructureShape_Shape_BigAngle				= "BigAngle, Int8Bit";
static const std::string StructureShape_Shape_RadiusCoordinates		= "RadiusCoordinates, struct, X, Y";
static const std::string StructureShape_Shape_RadiusCoordinates_X	= "X, Int8Bit";
static const std::string StructureShape_Shape_RadiusCoordinates_Y	= "Y, Int8Bit";



// BasicItem Syntax:
// ---------------
static const char *BasicItemCommand = "BasicItem";

static const std::string BasicItemType			= "Type, enum, Elevator, Staircase_H, Staircase_V, WC, CarGate_Right, CarGate_Left, CarGate_Up, CarGate_Down, PayingMachine, Door, Sign, Column_Sqr, Column_Cir, Road";
static const std::string IsScaled				= "IsScaled, bool";
static const std::string X						= "X, union, Size16bits, Size10bits, Size6bits";
static const std::string X_Size16bits			= "X_Size16bits, Int16Bit";
static const std::string X_Size10bits			= "X_Size10bits, Int10Bit";
static const std::string X_Size6bits			= "X_Size6bits, Int6Bit";
static const std::string Y						= "Y, union, Size16bits, Size10bits, Size6bits";
static const std::string Y_Size16bits			= "Y_Size16bits, Int16Bit";
static const std::string Y_Size10bits			= "Y_Size10bits, Int10Bit";
static const std::string Y_Size6bits			= "Y_Size6bits, Int6Bit";

// Position Syntax:
// ---------------
static const char *PositionCommand = "Position";

static const std::string PositionItemType		= "Type, enum, CR, ForwardHorizontalJump, ForwardVerticalJump, ForwardDiagonalJump";
static const std::string dX						= "dX, Int8Bit";
static const std::string dY						= "dY, Int8Bit";

// SignedJump Syntax:
// ---------------
static const char *SignedJumpCommand = "SignedJump";

static const std::string SignedJumpItemType		= "Type, enum, CarriageDir, SignedHorizontalJump, SignedVerticalJump, SignedDiagonalJump";
static const std::string Signed_dX				= "dX, SignedInt8Bit";
static const std::string Signed_dY				= "dY, SignedInt8Bit";


// AbsoluteJump Syntax:
// ---------------
static const char *AbsoluteJumpCommand = "AbsoluteJump";

static const std::string AbsoluteJumpItemType		= "Type, enum, Unused, AbsoluteHorizontalJump, AbsoluteVerticalJump, AbsoluteDiagonalJump";
static const std::string Abs_X						= "X, Int16Bit";
static const std::string Abs_Y						= "Y, Int16Bit";


// ComplexItem Syntax:
// ---------------
static const char *ComplexItemCommand = "Complex";

static const std::string IsNew										= "IsNew, bool";
static const std::string UID										= "UID, Int5Bit";
static const std::string NumberOfObjectsInComplex					= "NumberOfObjects, Int5Bit";
static const std::string IsReplicationPartOfDefinition				= "IsReplicationPartOfDefinition, bool";
static const std::string IsVerticalMirror							= "IsVerticalMirror, bool";
static const std::string IsHorizontalMirror							= "IsHorizontalMirror, bool";
static const std::string IsVerticalReplication						= "IsVerticalReplication, bool";
static const std::string IsHorizontalReplication					= "IsHorizontalReplication, bool";
static const std::string VerticalReplication						= "VerticalReplication, struct, GapBetweenReplicas, TimesToReplicate";
static const std::string VerticalReplication_GapBetweenReplicas		= "GapBetweenReplicas, Int6Bit";
static const std::string VerticalReplication_TimesToReplicate		= "TimesToReplicate, Int6Bit";
static const std::string HorizontalReplication						= "HorizontalReplication, struct, GapBetweenReplicas, TimesToReplicate";
static const std::string HorizontalReplication_GapBetweenReplicas	= "GapBetweenReplicas, Int6Bit";
static const std::string HorizontalReplication_TimesToReplicate		= "TimesToReplicate, Int6Bit";


// Pavement Syntax:
// ---------------
static const char *PavementCommand = "Pavement";

static const std::string Shape								= "Shape, enum, Wall, Right_Triangle, Triangle, Rect, Quadrangle, Pentagon";
static const std::string Texture							= "Texture, enum, Texture_Pavement, Texture_Building, Texture_NoParking, SolidFill";
static const std::string FillType							= "Fill, Int4Bit";
static const std::string IsAdjacentToParking				= "IsAdjacentToParking, bool";
static const std::string IsCircular							= "IsCircular, bool";
static const std::string SizeOrSide							= "SizeOrSide, union, Side, Size";
static const std::string SizeOrSide_Side					= "Side, bool";
static const std::string SizeOrSide_ReducedSize				= "ReducedSize, bool";
static const std::string SpecialVertexCurvature				= "SpecialVertexCurvature, struct, Type, IsCircular";
static const std::string SpecialVertexCurvature_Type		= "Type, enum, Linear, Convex, Concave, Rectangular";
static const std::string SpecialVertexCurvature_IsCircular	= "IsCircular, bool";
static const std::string ShortenVertexCoordinate			= "ShortenVertexCoordinate, Int6Bit";
static const std::string VertexList										= "VertexList, list, 0, 4" ; 
static const std::string VertexList_VertexParameters					= "Vertex, struct, X, Y, CurvatureType, IsCircular";
static const std::string VertexList_VertexParameters_X					= "X, union, Size8bits, Size6bits";
static const std::string VertexList_VertexParameters_X_Size8bits		= "Size8bits, Int8Bit";
static const std::string VertexList_VertexParameters_X_Size6bits		= "Size6bits, Int6Bit";
static const std::string VertexList_VertexParameters_Y					= "Y, union, Size8bits, Size6bits";
static const std::string VertexList_VertexParameters_Y_Size8bits		= "Size8bits, Int8Bit";
static const std::string VertexList_VertexParameters_Y_Size6bits		= "Size6bits, Int6Bit";
static const std::string VertexList_VertexParameters_CurvatureType		= "CurvatureType, enum, Linear, Convex, Concave, Rectangular";
static const std::string VertexList_VertexParameters_IsCircular			= "IsCircular, bool";

