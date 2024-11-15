# JsonWrapper
Some Json utilities to prevent repetitive code in Unreal Engine

## About

Very simple plugin wrapping built-in Json functionnalities in Unreal. Those being very verbose, the idea was to create wrapping functions to prevent too much repetitive code.

> [!NOTE]  
> These functions were tailored for my specific use. I just thought of sharing them with others as they save me some time.

> [!WARNING]  
> Supported Unreal versions: 5.4. (Did not try with older versions.)

### Functions

- Serialize Json (from Json object to string)
- Deserialize Json (from string to Json object)
- Write Json object to file
- Load Json object from file

## Installation

###  Marketplace

(NOT YET)

### Manual installation

#### Global (all projects)

- Download release and extract in Unreal installation folder "/Epic Games/UE_[X].[Y]/Engine/Plugins/Marketplace/"

#### Local (specific project)

- Download release or clone repository (as submodule eventually) in your project folder in "/[ProjectName]/Plugins/"

Then it should show up in your project when you go to `"Edit/Plugins"`. 

## Dependencies

You can use code from the JsonWrapper plugin in your project or in other plugins. For this, you need to set up dependencies for the JsonWrapperRuntime module.
- Project Build.cs -> "/[ProjectName]/Source/[ProjectName]/[ProjectName].Build.cs"
- Other plugin Build.cs -> "/[ProjectName]/Plugins/[PluginName]/Source/[PluginModuleName]/[PluginModuleName].Build.cs"
- Other plugin Build.cs (alternative architecture) -> "/[ProjectName]/Plugins/[PluginName]/Source/[PluginModuleName].Build.cs"

If you use the code in another plugin, you might want to add a dependency for the JsonWrapper plugin in the .uplugin file.
- Open "/[ProjectName]/Plugins/[PluginName]/[PluginName].uplugin"
- Add `"JsonWrapper"` to `Plugins` (`{..., "Plugins": [..., {"Name": "JsonWrapper", "Enabled": true}]}`)

### Global installation

In the Build.cs file:
- Add `"JsonWrapperRuntime"` to `PublicDependencyModuleNames` (`PublicDependencyModuleNames.AddRange(new string[]{..., "JsonWrapperRuntime"});`)
- Add `"JsonWrapperRuntime/Public"` and `"JsonWrapperRuntime/Classes"` to `PublicIncludePaths` (`PublicIncludePaths.AddRange(new string[]{..., "JsonWrapperRuntime/Public", "JsonWrapperRuntime/Classes"});`)

### Local installation

In the Build.cs file:
- Add `"JsonWrapperRuntime"` to `PrivateDependencyModuleNames` (`PrivateDependencyModuleNames.AddRange(new string[]{..., "JsonWrapperRuntime"});`)
