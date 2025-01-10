// Copyright Sarah Frémann, 2024. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "JsonWrapperUtils.generated.h"

/**
 * Wrapping utilities to avoid repetitive code when using Unreal built-in Json functions 
 */
UCLASS()
class JSONWRAPPERRUNTIME_API UJsonWrapperUtils : public UObject
{
	GENERATED_BODY()

public:
	/** Serialize JsonObject to FString */
	static FString SerializeJson(TSharedPtr<FJsonObject> JsonObject);
	/** Deserialize FString to JsonObject - return false if failed */
	static bool DeserializeJson(TSharedPtr<FJsonObject>* JsonObject, const FString& SerializedJson);

	/** Serialize and write JsonObject to file */
	static void WriteJsonToFile(TSharedPtr<FJsonObject> JsonObject, const FString& Filename);
	/** Load and deserialize JsonObject from file - return false if failed */
	static bool LoadJsonFromFile(TSharedPtr<FJsonObject>* JsonObject, const FString& Filename);
};
