Pod::Spec.new do |s|
  s.name             = 'Verifie'
  s.version          = '0.4.0'
  s.summary          = 'Facial biometrics technology lets your users verify themselves anywhere, anytime.'
  s.description      = 'Intelligent Data Capture Powered by Machine Learning for Fast Customer Onboarding & Identity Verification.'
  s.platform          = :ios
  s.homepage          = 'https://verifie.ai'
  s.license           = { :type => 'Commercial', :file => 'LICENSE' }
  s.author            = 'Oxygen LLC'
  s.source            = { :git => 'https://github.com/verifie-global/verifie-iOS.git', :tag => "v#{s.version}"}

  s.ios.deployment_target = '11.0'
  s.swift_version = '5.0'
  
  s.vendored_frameworks = 'Verifie.framework'
  s.preserve_paths = '*.framework'
  
  s.dependency 'Alamofire', '5.2'
  s.dependency 'SVProgressHUD', '2.2.5'
  s.dependency 'QKMRZParser', '1.0.1'
  s.dependency 'SwiftyTesseract', '3.0'
end
