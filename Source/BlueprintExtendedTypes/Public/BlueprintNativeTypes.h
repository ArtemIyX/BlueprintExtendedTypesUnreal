// Developed by Wellsaik

#pragma once

#include "CoreMinimal.h"

#include "BlueprintNativeTypes.generated.h"

USTRUCT(BlueprintType, meta = (DisplayName = "Int8"))
struct BLUEPRINTEXTENDEDTYPES_API FBlueprintInt8
{
	GENERATED_BODY()

public:
	constexpr FBlueprintInt8() noexcept = default;

	explicit constexpr FBlueprintInt8(int8 InValue) noexcept
		: Value(InValue) {}

	constexpr int8 GetValue() const noexcept { return Value; }
	explicit constexpr operator int8() const noexcept { return Value; }
	constexpr bool operator==(const FBlueprintInt8& InOther) const noexcept { return Value == InOther.Value; }
	constexpr bool operator!=(const FBlueprintInt8& InOther) const noexcept { return Value != InOther.Value; }
	constexpr bool operator<(const FBlueprintInt8& InOther) const noexcept { return Value < InOther.Value; }
	constexpr bool operator<=(const FBlueprintInt8& InOther) const noexcept { return Value <= InOther.Value; }
	constexpr bool operator>(const FBlueprintInt8& InOther) const noexcept { return Value > InOther.Value; }
	constexpr bool operator>=(const FBlueprintInt8& InOther) const noexcept { return Value >= InOther.Value; }
	friend uint32 GetTypeHash(const FBlueprintInt8& InValue) { return ::GetTypeHash(InValue.Value); }

private:
	UPROPERTY()
	int8 Value = 0;
};

USTRUCT(BlueprintType, meta = (DisplayName = "Int16"))
struct BLUEPRINTEXTENDEDTYPES_API FBlueprintInt16
{
	GENERATED_BODY()

public:
	constexpr FBlueprintInt16() noexcept = default;

	explicit constexpr FBlueprintInt16(int16 InValue) noexcept
		: Value(InValue) {}

	constexpr int16 GetValue() const noexcept { return Value; }
	explicit constexpr operator int16() const noexcept { return Value; }
	constexpr bool operator==(const FBlueprintInt16& InOther) const noexcept { return Value == InOther.Value; }
	constexpr bool operator!=(const FBlueprintInt16& InOther) const noexcept { return Value != InOther.Value; }
	constexpr bool operator<(const FBlueprintInt16& InOther) const noexcept { return Value < InOther.Value; }
	constexpr bool operator<=(const FBlueprintInt16& InOther) const noexcept { return Value <= InOther.Value; }
	constexpr bool operator>(const FBlueprintInt16& InOther) const noexcept { return Value > InOther.Value; }
	constexpr bool operator>=(const FBlueprintInt16& InOther) const noexcept { return Value >= InOther.Value; }
	friend uint32 GetTypeHash(const FBlueprintInt16& InValue) { return ::GetTypeHash(InValue.Value); }

private:
	UPROPERTY()
	int16 Value = 0;
};

USTRUCT(BlueprintType, meta = (DisplayName = "UInt16"))
struct BLUEPRINTEXTENDEDTYPES_API FBlueprintUInt16
{
	GENERATED_BODY()

public:
	constexpr FBlueprintUInt16() noexcept = default;

	explicit constexpr FBlueprintUInt16(uint16 InValue) noexcept
		: Value(InValue) {}

	constexpr uint16 GetValue() const noexcept { return Value; }
	explicit constexpr operator uint16() const noexcept { return Value; }
	constexpr bool operator==(const FBlueprintUInt16& InOther) const noexcept { return Value == InOther.Value; }
	constexpr bool operator!=(const FBlueprintUInt16& InOther) const noexcept { return Value != InOther.Value; }
	constexpr bool operator<(const FBlueprintUInt16& InOther) const noexcept { return Value < InOther.Value; }
	constexpr bool operator<=(const FBlueprintUInt16& InOther) const noexcept { return Value <= InOther.Value; }
	constexpr bool operator>(const FBlueprintUInt16& InOther) const noexcept { return Value > InOther.Value; }
	constexpr bool operator>=(const FBlueprintUInt16& InOther) const noexcept { return Value >= InOther.Value; }
	friend uint32 GetTypeHash(const FBlueprintUInt16& InValue) { return ::GetTypeHash(InValue.Value); }

private:
	UPROPERTY()
	uint16 Value = 0;
};

USTRUCT(BlueprintType, meta = (DisplayName = "UInt32"))
struct BLUEPRINTEXTENDEDTYPES_API FBlueprintUInt32
{
	GENERATED_BODY()

public:
	constexpr FBlueprintUInt32() noexcept = default;

	explicit constexpr FBlueprintUInt32(uint32 InValue) noexcept
		: Value(InValue) {}

	constexpr uint32 GetValue() const noexcept { return Value; }
	explicit constexpr operator uint32() const noexcept { return Value; }
	constexpr bool operator==(const FBlueprintUInt32& InOther) const noexcept { return Value == InOther.Value; }
	constexpr bool operator!=(const FBlueprintUInt32& InOther) const noexcept { return Value != InOther.Value; }
	constexpr bool operator<(const FBlueprintUInt32& InOther) const noexcept { return Value < InOther.Value; }
	constexpr bool operator<=(const FBlueprintUInt32& InOther) const noexcept { return Value <= InOther.Value; }
	constexpr bool operator>(const FBlueprintUInt32& InOther) const noexcept { return Value > InOther.Value; }
	constexpr bool operator>=(const FBlueprintUInt32& InOther) const noexcept { return Value >= InOther.Value; }
	friend uint32 GetTypeHash(const FBlueprintUInt32& InValue) { return ::GetTypeHash(InValue.Value); }

private:
	UPROPERTY()
	uint32 Value = 0;
};

USTRUCT(BlueprintType, meta = (DisplayName = "UInt64"))
struct BLUEPRINTEXTENDEDTYPES_API FBlueprintUInt64
{
	GENERATED_BODY()

public:
	constexpr FBlueprintUInt64() noexcept = default;

	explicit constexpr FBlueprintUInt64(uint64 InValue) noexcept
		: Value(InValue) {}

	constexpr uint64 GetValue() const noexcept { return Value; }
	explicit constexpr operator uint64() const noexcept { return Value; }
	constexpr bool operator==(const FBlueprintUInt64& InOther) const noexcept { return Value == InOther.Value; }
	constexpr bool operator!=(const FBlueprintUInt64& InOther) const noexcept { return Value != InOther.Value; }
	constexpr bool operator<(const FBlueprintUInt64& InOther) const noexcept { return Value < InOther.Value; }
	constexpr bool operator<=(const FBlueprintUInt64& InOther) const noexcept { return Value <= InOther.Value; }
	constexpr bool operator>(const FBlueprintUInt64& InOther) const noexcept { return Value > InOther.Value; }
	constexpr bool operator>=(const FBlueprintUInt64& InOther) const noexcept { return Value >= InOther.Value; }
	friend uint32 GetTypeHash(const FBlueprintUInt64& InValue) { return ::GetTypeHash(InValue.Value); }

private:
	UPROPERTY()
	uint64 Value = 0;
};