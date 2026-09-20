// Developed by Wellsaik

#include "BlueprintNativeTypesLibrary.h"

namespace BlueprintNativeTypes
{
	template <typename T>
	bool TryParseUnsigned(const FString& InValue, T& OutValue)
	{
		OutValue = 0;
		if (InValue.IsEmpty())
		{
			return false;
		}

		uint64 Result = 0;
		for (const TCHAR Character : InValue)
		{
			if (Character < TEXT('0') || Character > TEXT('9'))
			{
				return false;
			}

			const uint64 Digit = static_cast<uint64>(Character - TEXT('0'));
			if (Result > (static_cast<uint64>(TNumericLimits<T>::Max()) - Digit) / 10)
			{
				return false;
			}
			Result = Result * 10 + Digit;
		}

		OutValue = static_cast<T>(Result);
		return true;
	}

	template <typename T>
	bool TryParseSigned(const FString& InValue, T& OutValue)
	{
		OutValue = 0;
		if (InValue.IsEmpty())
		{
			return false;
		}

		const bool bNegative = InValue[0] == TEXT('-');
		const int32 StartIndex = bNegative ? 1 : 0;
		if (StartIndex == InValue.Len())
		{
			return false;
		}

		uint64 Result = 0;
		const uint64 Limit = bNegative
			? static_cast<uint64>(-(static_cast<int64>(TNumericLimits<T>::Min()) + 1)) + 1
			: static_cast<uint64>(TNumericLimits<T>::Max());
		for (int32 Index = StartIndex; Index < InValue.Len(); ++Index)
		{
			const TCHAR Character = InValue[Index];
			if (Character < TEXT('0') || Character > TEXT('9'))
			{
				return false;
			}

			const uint64 Digit = static_cast<uint64>(Character - TEXT('0'));
			if (Result > (Limit - Digit) / 10)
			{
				return false;
			}
			Result = Result * 10 + Digit;
		}

		if (bNegative)
		{
			OutValue = Result == Limit ? TNumericLimits<T>::Min() : static_cast<T>(-static_cast<int64>(Result));
		}
		else
		{
			OutValue = static_cast<T>(Result);
		}
		return true;
	}
}

#define IMPLEMENT_SIGNED_TYPE(Name, Wrapper, Native, MinValue, MaxValue) \
bool UBlueprintNativeTypesLibrary::TryMake##Name(int32 Value, Wrapper& OutValue) { OutValue = Wrapper(); if (Value < MinValue || Value > MaxValue) return false; OutValue = Wrapper(static_cast<Native>(Value)); return true; } \
int32 UBlueprintNativeTypesLibrary::Break##Name(Wrapper Value) { return static_cast<int32>(Value.GetValue()); } \
FString UBlueprintNativeTypesLibrary::Name##ToString(Wrapper Value) { return LexToString(Value.GetValue()); } \
bool UBlueprintNativeTypesLibrary::TryParse##Name(const FString& Value, Wrapper& OutValue) { OutValue = Wrapper(); Native Parsed = 0; if (!BlueprintNativeTypes::TryParseSigned(Value, Parsed)) return false; OutValue = Wrapper(Parsed); return true; } \
bool UBlueprintNativeTypesLibrary::Equal##Name(Wrapper A, Wrapper B) { return A == B; } \
bool UBlueprintNativeTypesLibrary::NotEqual##Name(Wrapper A, Wrapper B) { return A != B; } \
bool UBlueprintNativeTypesLibrary::Less##Name(Wrapper A, Wrapper B) { return A < B; } \
bool UBlueprintNativeTypesLibrary::LessOrEqual##Name(Wrapper A, Wrapper B) { return A <= B; } \
bool UBlueprintNativeTypesLibrary::Greater##Name(Wrapper A, Wrapper B) { return A > B; } \
bool UBlueprintNativeTypesLibrary::GreaterOrEqual##Name(Wrapper A, Wrapper B) { return A >= B; } \
Wrapper UBlueprintNativeTypesLibrary::Min##Name(Wrapper A, Wrapper B) { return A < B ? A : B; } \
Wrapper UBlueprintNativeTypesLibrary::Max##Name(Wrapper A, Wrapper B) { return A < B ? B : A; } \
Wrapper UBlueprintNativeTypesLibrary::Clamp##Name(Wrapper Value, Wrapper Min, Wrapper Max) { return Wrapper(FMath::Clamp(Value.GetValue(), Min.GetValue(), Max.GetValue())); }

IMPLEMENT_SIGNED_TYPE(Int8, FBlueprintInt8, int8, MIN_int8, MAX_int8)
IMPLEMENT_SIGNED_TYPE(Int16, FBlueprintInt16, int16, MIN_int16, MAX_int16)

#undef IMPLEMENT_SIGNED_TYPE

FBlueprintInt16 UBlueprintNativeTypesLibrary::Int8ToInt16(FBlueprintInt8 Value) { return FBlueprintInt16(Value.GetValue()); }
int32 UBlueprintNativeTypesLibrary::Int8ToInt32(FBlueprintInt8 Value) { return Value.GetValue(); }
int64 UBlueprintNativeTypesLibrary::Int8ToInt64(FBlueprintInt8 Value) { return Value.GetValue(); }
bool UBlueprintNativeTypesLibrary::TryInt16ToInt8(FBlueprintInt16 Value, FBlueprintInt8& OutValue) { return TryMakeInt8(Value.GetValue(), OutValue); }
int32 UBlueprintNativeTypesLibrary::Int16ToInt32(FBlueprintInt16 Value) { return Value.GetValue(); }
int64 UBlueprintNativeTypesLibrary::Int16ToInt64(FBlueprintInt16 Value) { return Value.GetValue(); }

#define IMPLEMENT_UNSIGNED_TYPE(Name, Wrapper, Native, Carrier, MaxValue) \
bool UBlueprintNativeTypesLibrary::TryMake##Name(Carrier Value, Wrapper& OutValue) { OutValue = Wrapper(); if (Value < 0 || Value > MaxValue) return false; OutValue = Wrapper(static_cast<Native>(Value)); return true; } \
Carrier UBlueprintNativeTypesLibrary::Break##Name(Wrapper Value) { return static_cast<Carrier>(Value.GetValue()); } \
FString UBlueprintNativeTypesLibrary::Name##ToString(Wrapper Value) { return LexToString(Value.GetValue()); } \
bool UBlueprintNativeTypesLibrary::TryParse##Name(const FString& Value, Wrapper& OutValue) { OutValue = Wrapper(); Native Parsed = 0; if (!BlueprintNativeTypes::TryParseUnsigned(Value, Parsed)) return false; OutValue = Wrapper(Parsed); return true; } \
bool UBlueprintNativeTypesLibrary::Equal##Name(Wrapper A, Wrapper B) { return A == B; } \
bool UBlueprintNativeTypesLibrary::NotEqual##Name(Wrapper A, Wrapper B) { return A != B; } \
bool UBlueprintNativeTypesLibrary::Less##Name(Wrapper A, Wrapper B) { return A < B; } \
bool UBlueprintNativeTypesLibrary::LessOrEqual##Name(Wrapper A, Wrapper B) { return A <= B; } \
bool UBlueprintNativeTypesLibrary::Greater##Name(Wrapper A, Wrapper B) { return A > B; } \
bool UBlueprintNativeTypesLibrary::GreaterOrEqual##Name(Wrapper A, Wrapper B) { return A >= B; } \
Wrapper UBlueprintNativeTypesLibrary::Min##Name(Wrapper A, Wrapper B) { return A < B ? A : B; } \
Wrapper UBlueprintNativeTypesLibrary::Max##Name(Wrapper A, Wrapper B) { return A < B ? B : A; } \
Wrapper UBlueprintNativeTypesLibrary::Clamp##Name(Wrapper Value, Wrapper Min, Wrapper Max) { return Wrapper(FMath::Clamp(Value.GetValue(), Min.GetValue(), Max.GetValue())); }

IMPLEMENT_UNSIGNED_TYPE(UInt16, FBlueprintUInt16, uint16, int32, MAX_uint16)
IMPLEMENT_UNSIGNED_TYPE(UInt32, FBlueprintUInt32, uint32, int64, MAX_uint32)

#undef IMPLEMENT_UNSIGNED_TYPE

int32 UBlueprintNativeTypesLibrary::UInt16ToInt32(FBlueprintUInt16 Value) { return Value.GetValue(); }
int64 UBlueprintNativeTypesLibrary::UInt16ToInt64(FBlueprintUInt16 Value) { return Value.GetValue(); }
FBlueprintUInt32 UBlueprintNativeTypesLibrary::UInt16ToUInt32(FBlueprintUInt16 Value) { return FBlueprintUInt32(Value.GetValue()); }
FBlueprintUInt64 UBlueprintNativeTypesLibrary::UInt16ToUInt64(FBlueprintUInt16 Value) { return FBlueprintUInt64(Value.GetValue()); }

bool UBlueprintNativeTypesLibrary::TryUInt32ToInt32(FBlueprintUInt32 Value, int32& OutValue)
{
	OutValue = 0;
	if (Value.GetValue() > MAX_int32)
		return false;
	OutValue = static_cast<int32>(Value.GetValue());
	return true;
}

int64 UBlueprintNativeTypesLibrary::UInt32ToInt64(FBlueprintUInt32 Value) { return Value.GetValue(); }
FBlueprintUInt64 UBlueprintNativeTypesLibrary::UInt32ToUInt64(FBlueprintUInt32 Value) { return FBlueprintUInt64(Value.GetValue()); }

bool UBlueprintNativeTypesLibrary::TryMakeUInt64FromInt64(const int64 Value, FBlueprintUInt64& OutValue)
{
	OutValue = FBlueprintUInt64();
	if (Value < 0)
		return false;
	OutValue = FBlueprintUInt64(static_cast<uint64>(Value));
	return true;
}

FString UBlueprintNativeTypesLibrary::BreakUInt64(const FBlueprintUInt64 Value) { return UInt64ToString(Value); }
FString UBlueprintNativeTypesLibrary::UInt64ToString(const FBlueprintUInt64 Value) { return LexToString(Value.GetValue()); }

bool UBlueprintNativeTypesLibrary::TryParseUInt64(const FString& Value, FBlueprintUInt64& OutValue)
{
	OutValue = FBlueprintUInt64();
	uint64 Parsed = 0;
	if (!BlueprintNativeTypes::TryParseUnsigned(Value, Parsed))
		return false;
	OutValue = FBlueprintUInt64(Parsed);
	return true;
}

bool UBlueprintNativeTypesLibrary::TryUInt64ToInt64(const FBlueprintUInt64 Value, int64& OutValue)
{
	OutValue = 0;
	if (Value.GetValue() > static_cast<uint64>(MAX_int64))
		return false;
	OutValue = static_cast<int64>(Value.GetValue());
	return true;
}

bool UBlueprintNativeTypesLibrary::EqualUInt64(FBlueprintUInt64 A, FBlueprintUInt64 B) { return A == B; }
bool UBlueprintNativeTypesLibrary::NotEqualUInt64(FBlueprintUInt64 A, FBlueprintUInt64 B) { return A != B; }
bool UBlueprintNativeTypesLibrary::LessUInt64(FBlueprintUInt64 A, FBlueprintUInt64 B) { return A < B; }
bool UBlueprintNativeTypesLibrary::LessOrEqualUInt64(FBlueprintUInt64 A, FBlueprintUInt64 B) { return A <= B; }
bool UBlueprintNativeTypesLibrary::GreaterUInt64(FBlueprintUInt64 A, FBlueprintUInt64 B) { return A > B; }
bool UBlueprintNativeTypesLibrary::GreaterOrEqualUInt64(FBlueprintUInt64 A, FBlueprintUInt64 B) { return A >= B; }
FBlueprintUInt64 UBlueprintNativeTypesLibrary::MinUInt64(FBlueprintUInt64 A, FBlueprintUInt64 B) { return A < B ? A : B; }
FBlueprintUInt64 UBlueprintNativeTypesLibrary::MaxUInt64(FBlueprintUInt64 A, FBlueprintUInt64 B) { return A < B ? B : A; }
FBlueprintUInt64 UBlueprintNativeTypesLibrary::ClampUInt64(FBlueprintUInt64 Value, FBlueprintUInt64 Min, FBlueprintUInt64 Max) { return FBlueprintUInt64(FMath::Clamp(Value.GetValue(), Min.GetValue(), Max.GetValue())); }