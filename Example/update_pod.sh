#!/bin/bash
rm -frd Pods/
rm -f ./Podfile.lock
rm -rfd IntelitySIP.xcworkspace
pod install
