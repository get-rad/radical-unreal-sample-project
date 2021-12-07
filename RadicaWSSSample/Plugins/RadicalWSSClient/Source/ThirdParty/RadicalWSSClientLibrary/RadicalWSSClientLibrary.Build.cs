// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class RadicalWSSClientLibrary : ModuleRules
{
	public RadicalWSSClientLibrary(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			// Add the import library
			//PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "x64", "Release", "ExampleLibrary.lib"));
			PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "RadicalLiveClient", "lib", "sioclient.lib"));
			PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "RadicalLiveClient", "lib", "sioclient_tls.lib"));

			PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "RadicalLiveClient", "RadicalLiveClient.lib"));

			// Delay-load the DLL, so we can load it from the right place first
			PublicDelayLoadDLLs.Add("libcrypto-3-x64.dll");
			PublicDelayLoadDLLs.Add("libssl-3-x64.dll");

			// Ensure that the DLL is staged along with the executable
			RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/RadicalLiveClient/libcrypto-3-x64.dll");
			RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/RadicalLiveClient/libssl-3-x64.dll");
			RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/RadicalLiveClient/sioclient.lib");
			RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/RadicalLiveClient/sioclient_tls.lib");



		}
		//else if (Target.Platform == UnrealTargetPlatform.Mac)
		//{
		//    PublicDelayLoadDLLs.Add(Path.Combine(ModuleDirectory, "Mac", "Release", "libExampleLibrary.dylib"));
		//    RuntimeDependencies.Add("$(PluginDir)/Source/ThirdParty/RadicalWSSClientLibrary/Mac/Release/libExampleLibrary.dylib");
		//}
	}
}
