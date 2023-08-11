{
  "targets": [
    {
      "target_name": "addon",
      "sources": ["src/addon.cpp"],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    }
  ],
  "target_defaults": {
    "conditions": [
      ["OS == 'win'", {
        "sources": ["src/addon.cpp"]
      }]
    ]
  }
}
