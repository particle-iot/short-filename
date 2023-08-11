# short-filename

On Windows, this module calls [GetShortPathNameW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getshortpathnamew) to convert a path like `C:\Program Files` to `C:\\PROGRA~1`. On other OSes, it returns the input path.

## Installation

```
npm install short-filename
```

## Usage

```
const shortFilename = require('short-filename');
console.log(shortFilename('C:\\Program Files\\Microsoft Office'));
// C:\PROGRA~1\MICROS~2 
```

## License

Copyright &copy; 2023 Particle Industries, Inc. Released under the MIT license