// Developed by Wellsaik

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlueprintNativeTypes.h"
#include "BlueprintNativeTypesLibrary.generated.h"

UCLASS()
class BLUEPRINTEXTENDEDTYPES_API UBlueprintNativeTypesLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Blueprint Extended Types|Int8", meta = (DisplayName = "Try Make Int8", ToolTip = "Creates an Int8 when Value is between -128 and 127."))
	static bool TryMakeInt8(int32 Value, FBlueprintInt8& OutValue);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Int8", meta = (DisplayName = "Break Int8", ToolTip = "Returns the exact Int8 value as an Integer."))
	static int32 BreakInt8(FBlueprintInt8 Value);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Int8", meta = (DisplayName = "Int8 To String", ToolTip = "Formats Int8 using invariant base-10 digits."))
	static FString Int8ToString(FBlueprintInt8 Value);
	UFUNCTION(BlueprintCallable, Category = "Blueprint Extended Types|Int8", meta = (DisplayName = "Try Parse Int8", ToolTip = "Parses canonical signed decimal Int8 text."))
	static bool TryParseInt8(const FString& Value, FBlueprintInt8& OutValue);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Int8", meta = (DisplayName = "Equal Int8"))
	static bool EqualInt8(FBlueprintInt8 A, FBlueprintInt8 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Int8", meta = (DisplayName = "Not Equal Int8"))
	static bool NotEqualInt8(FBlueprintInt8 A, FBlueprintInt8 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Int8", meta = (DisplayName = "Less Int8"))
	static bool LessInt8(FBlueprintInt8 A, FBlueprintInt8 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Int8", meta = (DisplayName = "Less or Equal Int8"))
	static bool LessOrEqualInt8(FBlueprintInt8 A, FBlueprintInt8 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Int8", meta = (DisplayName = "Greater Int8"))
	static bool GreaterInt8(FBlueprintInt8 A, FBlueprintInt8 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Int8", meta = (DisplayName = "Greater or Equal Int8"))
	static bool GreaterOrEqualInt8(FBlueprintInt8 A, FBlueprintInt8 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Int8", meta = (DisplayName = "Min Int8"))
	static FBlueprintInt8 MinInt8(FBlueprintInt8 A, FBlueprintInt8 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Int8", meta = (DisplayName = "Max Int8"))
	static FBlueprintInt8 MaxInt8(FBlueprintInt8 A, FBlueprintInt8 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Int8", meta = (DisplayName = "Clamp Int8"))
	static FBlueprintInt8 ClampInt8(FBlueprintInt8 Value, FBlueprintInt8 Min, FBlueprintInt8 Max);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Conversions", meta = (DisplayName = "Int8 To Int16", BlueprintAutocast, ToolTip = "Losslessly converts Int8 to Int16."))
	static FBlueprintInt16 Int8ToInt16(FBlueprintInt8 Value);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Conversions", meta = (DisplayName = "Int8 To Integer", BlueprintAutocast, ToolTip = "Losslessly converts Int8 to Integer."))
	static int32 Int8ToInt32(FBlueprintInt8 Value);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Conversions", meta = (DisplayName = "Int8 To Integer64", BlueprintAutocast, ToolTip = "Losslessly converts Int8 to Integer64."))
	static int64 Int8ToInt64(FBlueprintInt8 Value);

	UFUNCTION(BlueprintCallable, Category = "Blueprint Extended Types|Int16", meta = (DisplayName = "Try Make Int16", ToolTip = "Creates an Int16 when Value is between -32768 and 32767."))
	static bool TryMakeInt16(int32 Value, FBlueprintInt16& OutValue);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Int16", meta = (DisplayName = "Break Int16"))
	static int32 BreakInt16(FBlueprintInt16 Value);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Int16", meta = (DisplayName = "Int16 To String"))
	static FString Int16ToString(FBlueprintInt16 Value);
	UFUNCTION(BlueprintCallable, Category = "Blueprint Extended Types|Int16", meta = (DisplayName = "Try Parse Int16"))
	static bool TryParseInt16(const FString& Value, FBlueprintInt16& OutValue);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Int16", meta = (DisplayName = "Equal Int16"))
	static bool EqualInt16(FBlueprintInt16 A, FBlueprintInt16 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Int16", meta = (DisplayName = "Not Equal Int16"))
	static bool NotEqualInt16(FBlueprintInt16 A, FBlueprintInt16 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Int16", meta = (DisplayName = "Less Int16"))
	static bool LessInt16(FBlueprintInt16 A, FBlueprintInt16 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Int16", meta = (DisplayName = "Less or Equal Int16"))
	static bool LessOrEqualInt16(FBlueprintInt16 A, FBlueprintInt16 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Int16", meta = (DisplayName = "Greater Int16"))
	static bool GreaterInt16(FBlueprintInt16 A, FBlueprintInt16 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Int16", meta = (DisplayName = "Greater or Equal Int16"))
	static bool GreaterOrEqualInt16(FBlueprintInt16 A, FBlueprintInt16 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Int16", meta = (DisplayName = "Min Int16"))
	static FBlueprintInt16 MinInt16(FBlueprintInt16 A, FBlueprintInt16 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Int16", meta = (DisplayName = "Max Int16"))
	static FBlueprintInt16 MaxInt16(FBlueprintInt16 A, FBlueprintInt16 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Int16", meta = (DisplayName = "Clamp Int16"))
	static FBlueprintInt16 ClampInt16(FBlueprintInt16 Value, FBlueprintInt16 Min, FBlueprintInt16 Max);
	UFUNCTION(BlueprintCallable, Category = "Blueprint Extended Types|Conversions", meta = (DisplayName = "Try Convert Int16 To Int8", ToolTip = "Converts Int16 when it fits Int8."))
	static bool TryInt16ToInt8(FBlueprintInt16 Value, FBlueprintInt8& OutValue);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Conversions", meta = (DisplayName = "Int16 To Integer", BlueprintAutocast, ToolTip = "Losslessly converts Int16 to Integer."))
	static int32 Int16ToInt32(FBlueprintInt16 Value);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Conversions", meta = (DisplayName = "Int16 To Integer64", BlueprintAutocast, ToolTip = "Losslessly converts Int16 to Integer64."))
	static int64 Int16ToInt64(FBlueprintInt16 Value);

	UFUNCTION(BlueprintCallable, Category = "Blueprint Extended Types|UInt16", meta = (DisplayName = "Try Make UInt16", ToolTip = "Creates a UInt16 when Value is between 0 and 65535."))
	static bool TryMakeUInt16(int32 Value, FBlueprintUInt16& OutValue);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt16", meta = (DisplayName = "Break UInt16"))
	static int32 BreakUInt16(FBlueprintUInt16 Value);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt16", meta = (DisplayName = "UInt16 To String"))
	static FString UInt16ToString(FBlueprintUInt16 Value);
	UFUNCTION(BlueprintCallable, Category = "Blueprint Extended Types|UInt16", meta = (DisplayName = "Try Parse UInt16"))
	static bool TryParseUInt16(const FString& Value, FBlueprintUInt16& OutValue);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt16", meta = (DisplayName = "Equal UInt16"))
	static bool EqualUInt16(FBlueprintUInt16 A, FBlueprintUInt16 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt16", meta = (DisplayName = "Not Equal UInt16"))
	static bool NotEqualUInt16(FBlueprintUInt16 A, FBlueprintUInt16 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt16", meta = (DisplayName = "Less UInt16"))
	static bool LessUInt16(FBlueprintUInt16 A, FBlueprintUInt16 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt16", meta = (DisplayName = "Less or Equal UInt16"))
	static bool LessOrEqualUInt16(FBlueprintUInt16 A, FBlueprintUInt16 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt16", meta = (DisplayName = "Greater UInt16"))
	static bool GreaterUInt16(FBlueprintUInt16 A, FBlueprintUInt16 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt16", meta = (DisplayName = "Greater or Equal UInt16"))
	static bool GreaterOrEqualUInt16(FBlueprintUInt16 A, FBlueprintUInt16 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt16", meta = (DisplayName = "Min UInt16"))
	static FBlueprintUInt16 MinUInt16(FBlueprintUInt16 A, FBlueprintUInt16 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt16", meta = (DisplayName = "Max UInt16"))
	static FBlueprintUInt16 MaxUInt16(FBlueprintUInt16 A, FBlueprintUInt16 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt16", meta = (DisplayName = "Clamp UInt16"))
	static FBlueprintUInt16 ClampUInt16(FBlueprintUInt16 Value, FBlueprintUInt16 Min, FBlueprintUInt16 Max);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Conversions", meta = (DisplayName = "UInt16 To Integer", BlueprintAutocast, ToolTip = "Losslessly converts UInt16 to Integer."))
	static int32 UInt16ToInt32(FBlueprintUInt16 Value);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Conversions", meta = (DisplayName = "UInt16 To Integer64", BlueprintAutocast, ToolTip = "Losslessly converts UInt16 to Integer64."))
	static int64 UInt16ToInt64(FBlueprintUInt16 Value);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Conversions", meta = (DisplayName = "UInt16 To UInt32", BlueprintAutocast, ToolTip = "Losslessly converts UInt16 to UInt32."))
	static FBlueprintUInt32 UInt16ToUInt32(FBlueprintUInt16 Value);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Conversions", meta = (DisplayName = "UInt16 To UInt64", BlueprintAutocast, ToolTip = "Losslessly converts UInt16 to UInt64."))
	static FBlueprintUInt64 UInt16ToUInt64(FBlueprintUInt16 Value);

	UFUNCTION(BlueprintCallable, Category = "Blueprint Extended Types|UInt32", meta = (DisplayName = "Try Make UInt32", ToolTip = "Creates a UInt32 when Value is between 0 and 4294967295."))
	static bool TryMakeUInt32(int64 Value, FBlueprintUInt32& OutValue);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt32", meta = (DisplayName = "Break UInt32"))
	static int64 BreakUInt32(FBlueprintUInt32 Value);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt32", meta = (DisplayName = "UInt32 To String"))
	static FString UInt32ToString(FBlueprintUInt32 Value);
	UFUNCTION(BlueprintCallable, Category = "Blueprint Extended Types|UInt32", meta = (DisplayName = "Try Parse UInt32"))
	static bool TryParseUInt32(const FString& Value, FBlueprintUInt32& OutValue);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt32", meta = (DisplayName = "Equal UInt32"))
	static bool EqualUInt32(FBlueprintUInt32 A, FBlueprintUInt32 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt32", meta = (DisplayName = "Not Equal UInt32"))
	static bool NotEqualUInt32(FBlueprintUInt32 A, FBlueprintUInt32 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt32", meta = (DisplayName = "Less UInt32"))
	static bool LessUInt32(FBlueprintUInt32 A, FBlueprintUInt32 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt32", meta = (DisplayName = "Less or Equal UInt32"))
	static bool LessOrEqualUInt32(FBlueprintUInt32 A, FBlueprintUInt32 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt32", meta = (DisplayName = "Greater UInt32"))
	static bool GreaterUInt32(FBlueprintUInt32 A, FBlueprintUInt32 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt32", meta = (DisplayName = "Greater or Equal UInt32"))
	static bool GreaterOrEqualUInt32(FBlueprintUInt32 A, FBlueprintUInt32 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt32", meta = (DisplayName = "Min UInt32"))
	static FBlueprintUInt32 MinUInt32(FBlueprintUInt32 A, FBlueprintUInt32 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt32", meta = (DisplayName = "Max UInt32"))
	static FBlueprintUInt32 MaxUInt32(FBlueprintUInt32 A, FBlueprintUInt32 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt32", meta = (DisplayName = "Clamp UInt32"))
	static FBlueprintUInt32 ClampUInt32(FBlueprintUInt32 Value, FBlueprintUInt32 Min, FBlueprintUInt32 Max);
	UFUNCTION(BlueprintCallable, Category = "Blueprint Extended Types|Conversions", meta = (DisplayName = "Try Convert UInt32 To Integer", ToolTip = "Converts UInt32 when it fits Integer."))
	static bool TryUInt32ToInt32(FBlueprintUInt32 Value, int32& OutValue);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Conversions", meta = (DisplayName = "UInt32 To Integer64", BlueprintAutocast, ToolTip = "Losslessly converts UInt32 to Integer64."))
	static int64 UInt32ToInt64(FBlueprintUInt32 Value);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|Conversions", meta = (DisplayName = "UInt32 To UInt64", BlueprintAutocast, ToolTip = "Losslessly converts UInt32 to UInt64."))
	static FBlueprintUInt64 UInt32ToUInt64(FBlueprintUInt32 Value);

	UFUNCTION(BlueprintCallable, Category = "Blueprint Extended Types|UInt64", meta = (DisplayName = "Try Make UInt64 From Integer64", ToolTip = "Creates a UInt64 from a nonnegative Integer64."))
	static bool TryMakeUInt64FromInt64(int64 Value, FBlueprintUInt64& OutValue);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt64", meta = (DisplayName = "Break UInt64", ToolTip = "Returns all UInt64 digits as an invariant decimal string."))
	static FString BreakUInt64(FBlueprintUInt64 Value);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt64", meta = (DisplayName = "UInt64 To String"))
	static FString UInt64ToString(FBlueprintUInt64 Value);
	UFUNCTION(BlueprintCallable, Category = "Blueprint Extended Types|UInt64", meta = (DisplayName = "Try Parse UInt64", ToolTip = "Parses unsigned decimal text up to 18446744073709551615."))
	static bool TryParseUInt64(const FString& Value, FBlueprintUInt64& OutValue);
	UFUNCTION(BlueprintCallable, Category = "Blueprint Extended Types|UInt64", meta = (DisplayName = "Try Convert UInt64 To Integer64", ToolTip = "Converts UInt64 when it fits in Integer64."))
	static bool TryUInt64ToInt64(FBlueprintUInt64 Value, int64& OutValue);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt64", meta = (DisplayName = "Equal UInt64"))
	static bool EqualUInt64(FBlueprintUInt64 A, FBlueprintUInt64 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt64", meta = (DisplayName = "Not Equal UInt64"))
	static bool NotEqualUInt64(FBlueprintUInt64 A, FBlueprintUInt64 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt64", meta = (DisplayName = "Less UInt64"))
	static bool LessUInt64(FBlueprintUInt64 A, FBlueprintUInt64 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt64", meta = (DisplayName = "Less or Equal UInt64"))
	static bool LessOrEqualUInt64(FBlueprintUInt64 A, FBlueprintUInt64 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt64", meta = (DisplayName = "Greater UInt64"))
	static bool GreaterUInt64(FBlueprintUInt64 A, FBlueprintUInt64 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt64", meta = (DisplayName = "Greater or Equal UInt64"))
	static bool GreaterOrEqualUInt64(FBlueprintUInt64 A, FBlueprintUInt64 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt64", meta = (DisplayName = "Min UInt64"))
	static FBlueprintUInt64 MinUInt64(FBlueprintUInt64 A, FBlueprintUInt64 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt64", meta = (DisplayName = "Max UInt64"))
	static FBlueprintUInt64 MaxUInt64(FBlueprintUInt64 A, FBlueprintUInt64 B);
	UFUNCTION(BlueprintPure, Category = "Blueprint Extended Types|UInt64", meta = (DisplayName = "Clamp UInt64"))
	static FBlueprintUInt64 ClampUInt64(FBlueprintUInt64 Value, FBlueprintUInt64 Min, FBlueprintUInt64 Max);


};