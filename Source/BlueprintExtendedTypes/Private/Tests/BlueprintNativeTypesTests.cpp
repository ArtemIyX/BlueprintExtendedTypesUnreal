// Developed by Wellsaik

#if WITH_DEV_AUTOMATION_TESTS

#include "BlueprintNativeTypes.h"
#include "BlueprintNativeTypesLibrary.h"
#include "Misc/AutomationTest.h"
#include "Serialization/MemoryReader.h"
#include "Serialization/MemoryWriter.h"
#include "UObject/UnrealType.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBlueprintNativeTypesNumericTest, "BlueprintExtendedTypes.NativeTypes.Numeric", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FBlueprintNativeTypesNumericTest::RunTest(const FString& Parameters)
{
	FBlueprintInt8 Int8;
	FBlueprintInt16 Int16;
	FBlueprintUInt16 UInt16;
	FBlueprintUInt32 UInt32;
	FBlueprintUInt64 UInt64;
	TestEqual(TEXT("Int8 defaults to zero"), Int8.GetValue(), static_cast<int8>(0));
	TestEqual(TEXT("Int16 defaults to zero"), Int16.GetValue(), static_cast<int16>(0));
	TestEqual(TEXT("UInt16 defaults to zero"), UInt16.GetValue(), static_cast<uint16>(0));
	TestEqual(TEXT("UInt32 defaults to zero"), UInt32.GetValue(), static_cast<uint32>(0));
	TestEqual(TEXT("UInt64 defaults to zero"), UInt64.GetValue(), static_cast<uint64>(0));

	TestTrue(TEXT("Int8 lower boundary"), UBlueprintNativeTypesLibrary::TryMakeInt8(-128, Int8));
	TestTrue(TEXT("Int8 upper boundary"), UBlueprintNativeTypesLibrary::TryMakeInt8(127, Int8));
	TestFalse(TEXT("Int8 below boundary"), UBlueprintNativeTypesLibrary::TryMakeInt8(-129, Int8));
	TestFalse(TEXT("Int8 above boundary"), UBlueprintNativeTypesLibrary::TryMakeInt8(128, Int8));
	TestTrue(TEXT("Int16 lower boundary"), UBlueprintNativeTypesLibrary::TryMakeInt16(-32768, Int16));
	TestTrue(TEXT("Int16 upper boundary"), UBlueprintNativeTypesLibrary::TryMakeInt16(32767, Int16));
	TestFalse(TEXT("Int16 below boundary"), UBlueprintNativeTypesLibrary::TryMakeInt16(-32769, Int16));
	TestFalse(TEXT("Int16 above boundary"), UBlueprintNativeTypesLibrary::TryMakeInt16(32768, Int16));
	TestTrue(TEXT("UInt16 upper boundary"), UBlueprintNativeTypesLibrary::TryMakeUInt16(65535, UInt16));
	TestFalse(TEXT("UInt16 rejects negative"), UBlueprintNativeTypesLibrary::TryMakeUInt16(-1, UInt16));
	TestFalse(TEXT("UInt16 above boundary"), UBlueprintNativeTypesLibrary::TryMakeUInt16(65536, UInt16));
	TestTrue(TEXT("UInt32 upper boundary"), UBlueprintNativeTypesLibrary::TryMakeUInt32(4294967295LL, UInt32));
	TestFalse(TEXT("UInt32 rejects negative"), UBlueprintNativeTypesLibrary::TryMakeUInt32(-1, UInt32));
	TestFalse(TEXT("UInt32 above boundary"), UBlueprintNativeTypesLibrary::TryMakeUInt32(4294967296LL, UInt32));

	TestTrue(TEXT("UInt64 maximum parses"), UBlueprintNativeTypesLibrary::TryParseUInt64(TEXT("18446744073709551615"), UInt64));
	TestEqual(TEXT("UInt64 formatting is exact"), UBlueprintNativeTypesLibrary::UInt64ToString(UInt64), FString(TEXT("18446744073709551615")));
	TestFalse(TEXT("UInt64 overflow rejects"), UBlueprintNativeTypesLibrary::TryParseUInt64(TEXT("18446744073709551616"), UInt64));
	TestFalse(TEXT("UInt64 plus sign rejects"), UBlueprintNativeTypesLibrary::TryParseUInt64(TEXT("+1"), UInt64));
	TestFalse(TEXT("UInt64 whitespace rejects"), UBlueprintNativeTypesLibrary::TryParseUInt64(TEXT(" 1"), UInt64));
	TestFalse(TEXT("UInt64 trailing text rejects"), UBlueprintNativeTypesLibrary::TryParseUInt64(TEXT("1x"), UInt64));
	TestTrue(TEXT("UInt64 above Integer64 parses"), UBlueprintNativeTypesLibrary::TryParseUInt64(TEXT("9223372036854775808"), UInt64));
	int64 SignedValue = 1;
	TestFalse(TEXT("UInt64 conversion to Integer64 rejects overflow"), UBlueprintNativeTypesLibrary::TryUInt64ToInt64(UInt64, SignedValue));
	TestEqual(TEXT("Failed UInt64 conversion zeroes output"), SignedValue, static_cast<int64>(0));

	TestTrue(TEXT("Int16 canonical parse"), UBlueprintNativeTypesLibrary::TryParseInt16(TEXT("-32768"), Int16));
	TestEqual(TEXT("Int16 canonical formatting"), UBlueprintNativeTypesLibrary::Int16ToString(Int16), FString(TEXT("-32768")));
	TestFalse(TEXT("Int16 whitespace rejects"), UBlueprintNativeTypesLibrary::TryParseInt16(TEXT(" 1"), Int16));
	TestFalse(TEXT("Int16 overflow rejects"), UBlueprintNativeTypesLibrary::TryParseInt16(TEXT("32768"), Int16));
	return true;
}

#endif
