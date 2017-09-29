{
  "variables": {
    "boost_dir": "D:/boost_1_65_1",
    "boost_lib": "D:/boost_1_65_1/stage/vc14-x64/lib/"
  },
  "targets": [
    {
      "target_name": "addon",
      "sources": [ "addon.cpp" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")",
        "<(boost_dir)"
      ],
      "link_settings": {
        "libraries": [
          "<(boost_lib)/libboost_filesystem-vc140-mt-s-1_65_1.lib",
          "<(boost_lib)/libboost_system-vc140-mt-s-1_65_1.lib"
        ]
      }
    }
  ]
}