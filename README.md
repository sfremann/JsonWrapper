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

For __global__ installation (all projects): download release and extract in Unreal installation folder `"/Epic Games/UE_[X].[Y]/Engine/Plugins/Marketplace/"`.

For __local__ installation (specific project): download release or clone repository (as submodule eventually) in your project folder in `"/[ProjectName]/Plugins/"`.

Then it should show up in your project when you go to `Edit > Plugins`.

### Dependencies

You can use code from the JsonWrapper plugin in your project or in other plugins. For this, you need to set up dependencies for the JsonWrapperRuntime module.
- __Project__ `Build.cs` -> "`/[ProjectName]/Source/[ProjectName]/[ProjectName].Build.cs"`
- __Other plugin__ `Build.cs` -> `"/[ProjectName]/Plugins/[PluginName]/Source/[PluginModuleName]/[PluginModuleName].Build.cs"`
- __Other plugin__ `Build.cs` (alternative architecture) -> `"/[ProjectName]/Plugins/[PluginName]/Source/[PluginModuleName].Build.cs"`

If you use the code in another plugin, you might want to add a dependency for the JsonWrapper plugin in the `.uplugin` file: open `"/[ProjectName]/Plugins/[PluginName]/[PluginName].uplugin"` and add `"JsonWrapper"` to `"Plugins"` (`{..., "Plugins": [..., {"Name": "JsonWrapper", "Enabled": true}]}`).

In the `Build.cs` file: add `"JsonWrapperRuntime"` to `PrivateDependencyModuleNames` (`PrivateDependencyModuleNames.AddRange(new string[]{..., "JsonWrapperRuntime"});`). This will allow you to include files from JsonWrapperRuntime module in your project/plugin's __private__ `.cpp` and `.h` files.

If you need to include files from JsonWrapperRuntime module in your project/plugin's __public__ `.h` files (e.g. if you want a class to inherit from one of the plugin's classes), in the `Build.cs` file: add `"JsonWrapperRuntime"` to `PublicDependencyModuleNames` (`PublicDependencyModuleNames.AddRange(new string[]{..., "JsonWrapperRuntime"});`).

If you run into trouble, you might need to do the following in the `Build.cs` file (but that should not be necessary):
- Add `"JsonWrapperRuntime/Public"` and `"JsonWrapperRuntime/Classes"` to `PublicIncludePaths` (`PublicIncludePaths.AddRange(new string[]{..., "JsonWrapperRuntime/Public", "JsonWrapperRuntime/Classes"});`)
- Add `"JsonWrapperRuntime/Public"` and `"JsonWrapperRuntime/Classes"` to `PrivateIncludePaths` (`PrivateIncludePaths.AddRange(new string[]{..., "JsonWrapperRuntime/Public", "JsonWrapperRuntime/Classes"});`)
