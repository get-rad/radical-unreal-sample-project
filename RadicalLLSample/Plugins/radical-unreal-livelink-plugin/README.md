# RADiCAL LIVE <-> Unreal Live Link Plugin

This plugin contains retargeting assets for converting animation output from RADiCAL LIVE to an Unreal Engine editor session. It also contains the RADiCAL UE Live Link Client, a web socket client that receives data from a remote RADiCAL LIVE server and makes it available to Unreal Live Link.    

## Initial Setup Instructions

To install, download the latest release for your engine version from the [Releases section](https://github.com/get-rad/radical-unreal-livelink-plugin/releases). Unzip to your project `/Plugins` or engine `Marketplace` folder, then enable the plugin in your project.

## Enable the RADiCAL Simulation Data Stream

The simulation data stream is made available to allow you to test the integration between RADiCAL and Unreal Live Link.  The simulation data looks exactly like the data made available through a RADiCAL LIVE session. Once the simulated data stream is successfully implemented, you'll switch the RADiCAL UE Live Link Client to the room name with the actual real-time data.  

###  Start RADiCAL’s simulation data stream

1. From your web browser, visit RADiCAL’s webpage hosting the simulation stream: https://getrad.co/live-unreal-simulation. 

   _Note: you may have to log into the RADiCAL website to access this page._

2. Copy and save elsewhere the auto-generated room name (in this example: “simulation_0r2d2”). You will need it later.  

   _Note: do not change the room name_.

3. Click “Connect”.  After a brief countdown, you will see a simulated motion data scene.  

   _Note: you can click `Esc` to exit full-screen mode_.

###  Enable the RADiCAL UE Live Link Client
 
1. Launch Windows File Explorer and navigate to the `RADiCAL_UELiveLinkClient` folder. Open a terminal window from that location, by clicking on “`Open Window Powershell`” from the `File` menu. 

2. You are now in your “terminal” that shows you’re inside the `RADiCAL_UELiveLinkClient` folder.

3. Type the following command: 
```.\RADiCAL_UELiveLinkClient.exe --serverUrl <serverUrl> --roomId <roomId> --authToken <authToken> --playerId <playerId>```

   Replace ```<serverUrl>``` get this from WP. // TODO: add location in wordpress

   Replace ```<authToken>``` get this from WP. https://getrad.co/my-account/account-key-page/

   Replace ```<roomId>``` with the room name auto-generated when you started the RADiCAL simulation stream. 

   Replace ```<playerId>``` get this from the visualizer, click to open editor, then click on a character

4. Click Enter. The RADiCAL UE Live Link Client will start. 
 
## Live Link Preview

After starting the Live Link stream through the RADiCAL UE Live Link Client, open the UE4 editor and go to Window -> Live Link. Go to Source -> Message Bus Source -> select the `RadLiveLink` source. You can now close this window.

We have provided two mannequins, one with the Epic skeleton and the other for the RADiCAL skeleton. The RADiCAL skeleton can be used as ground-truth for verifying animation data.

The Live Link data can be previewed inside the Skeleton, Skeletal Mesh, or Animation Blueprint windows for a given skeletal asset. 

On the right side, go to Preview Scene Settings, under Animation, change the Preview Controller to Live Link Preview Controller. Then, change the Live Link Subject Name to `RadicalPose`.

For Retarget Asset, select the corresponding Remap Asset file for that skeleton. For example, for the RADiCAL mannequin, choose the `RadToRadRemap` asset. For an Epic skeleton (either the provided Epic mannequin, or your project-specific character), choose the `BP_RadToEpicRemapAsset`. Assuming the target character uses an Epic skeleton, it should look as follows:

![Live Link Preview Setup](GALLERY_IMAGES/LiveLinkPreviewController.png)

## Live Link Source in AnimBP

To apply the incoming animation data to the characters in the scene, go to the AnimBP for the character and create a Live Link Pose node. Select the a) Live Link Subject Name and b) the Retarget Asset, like so:

![Live Link Pose node setup](GALLERY_IMAGES/LiveLinkPose.png)

Because of the difference between the RADiCAL skeleton (which defaults to a T pose) and the Unreal skeleton (which defaults to an A pose) we have to apply some rotations at the shoulder. Refer to the `AnimBP_EpicGames_Mannequin` AnimGraph and copy these transform nodes to your character:

![Transform Bone nodes](GALLERY_IMAGES/TransformBones.png)

## Multiplayer support (please go through previous steps first)

RADiCAL Live also supports multiplayer rooms, and we are working on improving the plug-in to make the experience integrated in the Unreal ecosystem. In the meantime we offer a more manual way of inputting our animation data in the Unreal Editor.

Let's first create two animation streams in the same room. On the simulation page:
https://getrad.co/live-unreal-simulation/
click to connect the first simulation. Once the character data is playing on the screen, click on the room name in the lower left corner to copy the room name to the clipcoard.

Open another tab with the simulation webpage and paste the room name from the first connected session. Click connect, and after the 3d assests load you should see two characters in the scene, eatch playing an animation cycle. These animations are streamed to your browser by our websocket server exactly the same way it would stream Live data.

Now you should open two comand line windows (either Command Prompt or Windows PowerShell), and navigate to your project that uses the RADiCAL Unreal plugin, then go inside `/Plugins/radical-unreal-livelink-plugin/RADiCAL_UELiveLinkClient` folder. We need to run the `RADiCAL_UELiveLinkClient.exe` command specifying both the room name we want to connect to and a unique player id for the character we want to receive data for. 

To get the character id, go back to one of the browser windows that shows the simulated streams, and click on a character. You will see the character ID in a box above the room name, in the lower right corner. If you click the other character this id will update. You can click on this box to copy the character ID to the clipboard.

Next, we will run the command with the ID from the first character in the first terminal window we've opened, and we will run it again in the second terminal with the ID from the other character. This will create two LiveLink Message Bus sources, each streaming animation data for its corresponding character. The following example shows the syntax of two commands that would create these sources:

```.\RADiCAL_UELiveLinkClientMulti.exe --roomId simulation_001 --playerId ISlm8srLM9BaBbwzAAAD```

```.\RADiCAL_UELiveLinkClientMulti.exe --roomId simulation_001 --playerId 4u_rVejQPnBhXqAXAAAF```

We now have LiveLink sources running in the background, time to play them in Unreal. In your Unreal Project, open the LiveLink window, and in `Sources` -> `Message Bus Sources` you should see the two RadicalLiveLink souces we created. Select both so you see them in the `source Type` list.

For every character you want to add its own animation source, you will have to create a duplicate of the main character blueprint and the animation blueprint corresponding to it. In our example (the sample Unreal project we provide), we will create a duplicate of the `BP_RADiCAL` character blueprint and the `AnimBP_RADiCAL_3-1` animation blueprint located in the `RADiCAL_Mannequin` folder. After creating the duplicate files, in our example `BP_RADiCAL_second` and `AnimBP_RADiCAL_3-1_2` double click on the new character blueprint, select the `SkeletalMesh` in the `Components` tab, and in the `Details` panel on the right, find the `Animation` tab, and select the duplicated animation in the `Anim Class` dropdown. (AnimBP_RADiCAL_3-1_2_C in our example)

![Char_blueprint](https://user-images.githubusercontent.com/7143949/144418700-73b5b65c-5cba-473d-95be-b42dd35eb139.png)

Next double click the Animation blueprint, go to the `AnimGraph` to the `Live Link Pose` node, and select from the dropdown one of the available sources. Make sure in the `Details` panel on the right, `Retarget Asset` dropdown has the `RadToRadRemapAsset` selected. You should now see the motion applied to your character.

![anim_blueprint](https://user-images.githubusercontent.com/7143949/144418738-678ba84f-efb4-4c88-8a30-139f56a9f3a9.png)


Open the other Animation blueprint and, in the `Live Link Pose` node, select the other source in the `Live Link Subject Name` dropdown. Now both characters will have their corresponding motion data applied to them.

Follow these simple steps to add as many characters and LiveLink sources as you want. 
 

## Rotation conversions for non-Epic skeletons (advanced users)

To account for some of the differences between the RADiCAL coordinate frame and Unreal, we have flipped the incoming LiveLink data's rotation and position axes. If you want to delve into the source C++, you can inspect the conversions at the `RadicalLiveLinkRemapAssetBase` class and its child classes. We expect that other skeletons will require different rotation adjustments, including swapping axes. We exposed three overridable methods to implement the root bone position, root bone rotation, and non-root bone rotation conversions. Please note that the AI output in RADiCAL uses the hip bone as a root, so position data should be mapped to the hips (or pelvis) in the target skeleton.
