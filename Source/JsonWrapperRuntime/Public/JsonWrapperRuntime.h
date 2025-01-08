// Copyright Milayr, 2024. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/**
 * JsonWrapper runtime module
 */
class FJsonWrapperRuntimeModule : public IModuleInterface
{
public:	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
