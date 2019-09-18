//
//  CustomHumanDetectorViewController.swift
//  VerifieFramework
//
//  Created by Misha Torosyan on 9/18/19.
//  Copyright © 2019 Misha Torosyan. All rights reserved.
//

import UIKit
import Verifie

@objc(CustomHumanDetectorViewController)

@objcMembers class CustomHumanDetectorViewController: VerifieBaseViewController,
                                                    VerifieHumanDetectorViewControllerInterface {

    @IBOutlet weak var previewView: VerifieVideoSessionPreviewView! {
        didSet {
            previewView.autorotate = false
        }
    }
    @IBOutlet private weak var statusLabel: UILabel!
    
    
    //    MARK: Lifecycle Functions
    override func viewDidLoad() {
        
        super.viewDidLoad()
        attemptRotationToPortrait()
    }
    
    
    //    MARK: - Internal Functions
    func update(statusText text: String) {
        
        statusLabel.text = text
    }
    
    
    //    MARK: - Private Functions
    private func attemptRotationToPortrait() {
        
        let value = UIInterfaceOrientation.portrait.rawValue
        UIDevice.current.setValue(value, forKey: "orientation")
        UINavigationController.attemptRotationToDeviceOrientation()
    }
}
