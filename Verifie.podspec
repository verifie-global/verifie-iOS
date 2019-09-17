Pod::Spec.new do |s|
  s.name             = 'Verifie'
  s.version          = '0.1.2'
  s.summary          = 'A short description of Verifie.'

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.platform          = :ios
  s.homepage          = 'https://www.verifie.com'
  s.license           = { :type => 'Commercial', :file => 'LICENSE' }
  s.author            = 'Arthur'
  s.source            = { :git => 'https://github.com/verifie-global/verifie-iOS.git', :tag => "v#{s.version}"}

  s.ios.deployment_target = '10.0'
  s.swift_version = '5.0'
  
  s.vendored_frameworks = 'Verifie.framework'
  s.preserve_paths = '*.framework'
  
  s.dependency 'Alamofire', '~> 5.0.0-rc.2'
  s.dependency 'OpenCV-Dynamic'
  s.dependency 'SVProgressHUD'  
end
