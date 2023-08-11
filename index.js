let nativeModule = null;

function shortFilename(inputPath) {
  if (process.platform === 'win32') {
    if (nativeModule === null) {
      nativeModule = require("node-gyp-build")(__dirname);
    }
    return nativeModule.getShortPathName(inputPath);
  } else {
    return inputPath;
  }
}

module.exports = shortFilename;