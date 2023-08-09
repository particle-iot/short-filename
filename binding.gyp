{
  "targets": [
    {
      "target_name": "addon",
      "sources": ["src/addon.cpp"]
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
