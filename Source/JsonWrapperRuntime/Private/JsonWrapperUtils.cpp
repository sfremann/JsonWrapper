// Copyright Milayr, 2024. All rights reserved.

#include "JsonWrapperUtils.h"

#include "Json.h"
#include "JsonObjectConverter.h"
#include "Kismet/KismetSystemLibrary.h"

/// <summary>
/// Serialize JSON to FString
/// </summary>
/// <param name="JsonObject">JSON object</param>
/// <returns>Serialized JSON</returns>
FString UJsonWrapperUtils::SerializeJson(TSharedPtr<FJsonObject> JsonObject)
{
    FString SerializedJson;
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&SerializedJson);
    FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);
    return SerializedJson;
}

/// <summary>
/// Deserialize FString to JSON
/// </summary>
/// <param name="JsonObject">JSON object</param>
/// <param name="SerializedJson">Serialized JSON</param>
/// <returns>false if failed</returns>
bool UJsonWrapperUtils::DeserializeJson(TSharedPtr<FJsonObject>* JsonObject, FString SerializedJson)
{
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(SerializedJson);
    return FJsonSerializer::Deserialize(Reader, *JsonObject);
}

/// <summary>
/// Serialize and write JSON to file
/// </summary>
/// <param name="JsonObject">JSON data to write</param>
/// <param name="Filename">File to write JSON data into</param>
void UJsonWrapperUtils::WriteJsonToFile(TSharedPtr<FJsonObject> JsonObject, FString Filename)
{
    FFileHelper::SaveStringToFile(SerializeJson(JsonObject), *Filename);
}

/// <summary>
/// Load JSON object from file
/// </summary>
/// <param name="JsonObject">JSON object to save data in</param>
/// <param name="Filename">File to retrieve JSON data from</param>
/// <returns>false if deserialization failed</returns>
bool UJsonWrapperUtils::LoadJsonFromFile(TSharedPtr<FJsonObject>* JsonObject, FString Filename)
{
    // Open JSON file and retrieve JSON data
    FString SerializedJson;

    if (FFileHelper::LoadFileToString(SerializedJson, *Filename))
    {
        // Deserialize JSON
        return DeserializeJson(JsonObject, SerializedJson);
    }

    return true;
}
