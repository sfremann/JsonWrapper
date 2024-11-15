// Copyright Milayr, 2024. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "JsonWrapperUtils.generated.h"

/**
 * Wrapping utilities to avoid repetitive code when using Unreal built-in Json functions 
 */
UCLASS()
class JSONWRAPPERRUNTIME_API UJsonWrapperUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static FString SerializeJson(TSharedPtr<FJsonObject> JsonObject);
	static bool DeserializeJson(TSharedPtr<FJsonObject>* JsonObject, FString SerializedJson);

	static void WriteJsonToFile(TSharedPtr<FJsonObject> JsonObject, FString Filename);
	static bool LoadJsonFromFile(TSharedPtr<FJsonObject>* JsonObject, FString Filename);
	
};
