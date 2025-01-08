// Copyright Milayr, 2024. All rights reserved.

#include "JsonWrapperUtils.h"

// Unreal dependencies
#include "Json.h"
#include "JsonObjectConverter.h"

FString UJsonWrapperUtils::SerializeJson(TSharedPtr<FJsonObject> JsonObject)
{
    FString SerializedJson;
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&SerializedJson);
    FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);
    return SerializedJson;
}

bool UJsonWrapperUtils::DeserializeJson(TSharedPtr<FJsonObject>* JsonObject, const FString& SerializedJson)
{
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(SerializedJson);
    return FJsonSerializer::Deserialize(Reader, *JsonObject);
}

void UJsonWrapperUtils::WriteJsonToFile(TSharedPtr<FJsonObject> JsonObject, const FString& Filename)
{
    FFileHelper::SaveStringToFile(SerializeJson(JsonObject), *Filename);
}

bool UJsonWrapperUtils::LoadJsonFromFile(TSharedPtr<FJsonObject>* JsonObject, const FString& Filename)
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
