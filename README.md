# Verifie
## Example

To run the example project, clone the repo, and run `pod install` from the Example directory.

## Installation

#### Cocoapods
- Verifie is available through [CocoaPods](https://cocoapods.org). To install it, simply add following lines to the top of your Podfile:

```
source 'https://github.com/CocoaPods/Specs.git'
source 'https://github.com/verifie-global/pod-specs.git'
```

- Then add the following line to your Podfile:

```pod 'Verifie', '~> 0.1.1'```

- Run `pod install`


#### Set privacy settings
- In your project's `Info.plist` file add these keys:  

**Key:** `NSMicrophoneUsageDescription`  
**Type:** `String`  
**Value:** `Usage description...`

**Key:** `NSPhotoLibraryAddUsageDescription`  
**Type:** `String`  
**Value:** `Usage description...`

**Key:** `NSPhotoLibraryUsageDescription`  
**Type:** `String`  
**Value:** `Usage description...`


## Errors
```
dyld: Library not loaded: /Users/"${USER}"/Library/Caches/CocoaPods/Pods/Release/OpenCV-Dynamic/4.0.1-bbf99/ios/build/build-iphonesimulator/lib/Release/opencv2.framework/opencv2
  Referenced from: /Users/"${USER}"/Library/Developer/CoreSimulator/Devices/AAD1EAA2-E169-414D-89CD-3B7C2398611A/data/Containers/Bundle/Application/9B0DC634-47B1-4557-9B28-B42561EDF1A9/Verifi-Test.app/Verifi-Test
  Reason: image not found
```

In case you are getting `image not found` error follow these steps to fix the issue:

1. Go to the directory that locates `opencv2.framework`.
    - type `cd /Users/"${USER}"/Library/Caches/CocoaPods/Pods/Release/OpenCV-Dynamic/4.0.1-bbf99/`. This path you can get from the error message.
1. If you type `otool -L opencv2.framework/opencv2` in your terminal, you should get something like this
``` 
$ otool -L opencv2.framework/opencv2
opencv2.framework/opencv2:
        /Users/alwc/projects/opencv/ios_arm64_dynamic_test/build/build-arm64-iphoneos/lib/Release/opencv2.framework/opencv2 (compatibility version 4.1.0, current version 4.1.0)
        /usr/lib/libc++.1.dylib (compatibility version 1.0.0, current version 400.9.4)
        /usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 1252.200.5)
```
Note that the `opencv2.framework/opencv2`'s parent (i.e. first file path) is a fixed path on your computer.

3. Now type 
`install_name_tool -id "@rpath/opencv2.framework/opencv2" opencv2.framework/opencv2` in your terminal and you'll see the `opencv2.framework/opencv2`'s parent has become @rpath:
```
$ otool -L opencv2.framework/opencv2 
opencv2.framework/opencv2:
        @rpath/opencv2.framework/opencv2 (compatibility version 4.1.0, current version 4.1.0)
        /usr/lib/libc++.1.dylib (compatibility version 1.0.0, current version 400.9.4)
        /usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 1252.200.5)
```

4. Then remove `yourProject/Pods/OpenCV-Dynamic` folder from your project and run `pod install` again.

These 4 steps should be able to solve your dynamic build problem.

*Source*: https://github.com/Legoless/OpenCV-Dynamic/issues/11#issuecomment-523261451


## Author
--

## License

Verifie is available under the Commercial license.
