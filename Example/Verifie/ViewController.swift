//
//  ViewController.swift
//  Verifie
//
//  Created by mixo44 on 09/08/2019.
//  Copyright (c) 2019 mixo44. All rights reserved.
//

import UIKit
import Verifie

class ViewController: UIViewController {
    
    var verifie: Verifie!
    @IBOutlet weak var imageView: UIImageView!
    @IBOutlet weak var textView: UITextView!
    
    var score: VerifieScore!
    var documents: [VerifieDocument] = []
    
    override func viewDidLoad() {
        
        super.viewDidLoad()
        
        //        let documentScannerViewController: CustomDocScannerViewController = CustomDocScannerViewController.load(from: .main)
        //        let humanDetectorViewController: CustomHumanDetectorViewController = CustomHumanDetectorViewController.load(from: .main)
        //        let viewControllersConfigs = VerifieViewControllersConfigs(documentScannerViewController: documentScannerViewController,
        //                                                                   humanDetectorViewController: humanDetectorViewController)
        
        let documentScannerConfigs = VerifieDocumentScannerConfigs.default()
        let configs = VerifieConfigs(licenseKey: "5d3f2e38-fe7c-43c6-b532-db9b57e674f8",
                                     personId: "12",
                                     textConfigs: VerifieTextConfigs.default(),
                                     viewControllersConfigs: /*viewControllersConfigs*/ nil,
                                     documentScannerConfigs: documentScannerConfigs)
        
        verifie = Verifie(configs: configs, delegate: self)
        
        verifie.start()
    }
    
    func showAlert(with message: String) {
        
        let alertController = UIAlertController(title: nil,
                                                message: message,
                                                preferredStyle: .alert)
        
        alertController.addAction(UIAlertAction(title: "OK",
                                                style: .cancel,
                                                handler: nil))
        
        UIApplication.topViewController()?.present(alertController, animated: true, completion: nil)
    }
    
    override func viewWillAppear(_ animated: Bool) {
        
        super.viewWillAppear(animated)
    }
    
    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
    }
}

extension ViewController: VerifieDelegate {
    
    func verifie(_ sender: Verifie, didReceive document: VerifieDocument) {
        
        if
            let documentImage = document.documentImage,
            let imageData = Data(base64Encoded: documentImage) {
            let image = UIImage(data: imageData)
            
            print("\(String(describing: image))")
        }
        
        documents.append(document)
    }
    
    func verifie(_ sender: Verifie, didCalculate score: VerifieScore) {
        
        if
            let faceImage = score.faceImage,
            let imageData = Data(base64Encoded: faceImage) {
            let image = UIImage(data: imageData)
            
            print("\(String(describing: image))")
        }
        
        self.score = score
        
        sender.stop()
        
        
        var fullText = "\(String(describing: score))\n\n"
        
        for document in documents {
            
            if
                let imageString = document.documentFaceImage,
                let imageData = Data(base64Encoded: imageString),
                let image = UIImage(data: imageData) {
                
                imageView.image = image
            }
            
            fullText.append("\(String(describing: document))\n\n")
        }
        
        textView.text = fullText
    }
    
    func verifie(_ sender: Verifie, didFailWith error: Error) {
        
        showAlert(with: error.localizedDescription)
    }
    
    func viewControllerToPresent(_ sender: Verifie) -> UIViewController {
        
        return self
    }
    
    func verifieDidFinish(_ sender: Verifie) {
        
        print("Verifie did finish job!")
    }
}

extension UIApplication {
    
    class func topViewController(controller: UIViewController? = UIApplication.shared.keyWindow?.rootViewController) -> UIViewController? {
        
        if let navigationController = controller as? UINavigationController {
            return topViewController(controller: navigationController.visibleViewController)
        }
        if let tabController = controller as? UITabBarController {
            if let selected = tabController.selectedViewController {
                return topViewController(controller: selected)
            }
        }
        if let presented = controller?.presentedViewController {
            return topViewController(controller: presented)
        }
        return controller
    }
}


public enum Storyboard: String {
    
    case main = "Main"
}

public extension UIViewController {
    
    static func load<T: UIViewController>(from storyboard: Storyboard = .main) -> T {
        
        let bundle = Bundle.main
        let storyboard = UIStoryboard(name: storyboard.rawValue, bundle: bundle)
        let selfName = String(describing: self)
        let viewController = storyboard.instantiateViewController(withIdentifier: selfName) as! T
        
        return viewController
    }
}
