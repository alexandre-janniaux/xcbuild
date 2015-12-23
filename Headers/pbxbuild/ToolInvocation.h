/**
 Copyright (c) 2015-present, Facebook, Inc.
 All rights reserved.

 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree. An additional grant
 of patent rights can be found in the PATENTS file in the same directory.
 */

#ifndef __pbxbuild_ToolInvocation_h
#define __pbxbuild_ToolInvocation_h

#include <pbxbuild/Base.h>

namespace pbxbuild {

class ToolInvocation {
public:
    class AuxiliaryFile {
    private:
        std::string        _path;
        std::vector<char> _contents;
        bool              _executable;

    public:
        AuxiliaryFile(std::string const &path, std::vector<char> const &contents, bool executable);
        AuxiliaryFile(std::string const &path, std::string const &contents, bool executable);
        ~AuxiliaryFile();

    public:
        std::string const &path() const
        { return _path; }
        std::vector<char> const &contents() const
        { return _contents; }
        bool executable() const
        { return _executable; }
    };

private:
    std::string                                  _executable;
    std::vector<std::string>                     _arguments;
    std::unordered_map<std::string, std::string> _environment;
    std::string                                  _workingDirectory;

private:
    std::vector<std::string>                     _inputs;
    std::vector<std::string>                     _outputs;
    std::vector<std::string>                     _phonyInputs;

private:
    std::vector<std::string>                     _inputDependencies;
    std::vector<std::string>                     _orderDependencies;
    std::vector<std::string>                     _outputDependencies;

private:
    std::string                                  _dependencyInfo;
    std::vector<AuxiliaryFile>                   _auxiliaryFiles;

private:
    std::string                                  _logMessage;
    bool                                         _showEnvironmentInLog;

public:
    ToolInvocation();
    ~ToolInvocation();

public:
    std::string const &executable() const
    { return _executable; }
    std::vector<std::string> const &arguments() const
    { return _arguments; }
    std::unordered_map<std::string, std::string> const &environment() const
    { return _environment; }
    std::string const &workingDirectory() const
    { return _workingDirectory; }

public:
    std::string &executable()
    { return _executable; }
    std::vector<std::string> &arguments()
    { return _arguments; }
    std::unordered_map<std::string, std::string> &environment()
    { return _environment; }
    std::string &workingDirectory()
    { return _workingDirectory; }

public:
    std::vector<std::string> const &inputs() const
    { return _inputs; }
    std::vector<std::string> const &outputs() const
    { return _outputs; }
    std::vector<std::string> const &phonyInputs() const
    { return _phonyInputs; }

public:
    std::vector<std::string> &inputs()
    { return _inputs; }
    std::vector<std::string> &outputs()
    { return _outputs; }
    std::vector<std::string> &phonyInputs()
    { return _phonyInputs; }

public:
    std::vector<std::string> const &inputDependencies() const
    { return _inputDependencies; }
    std::vector<std::string> const &orderDependencies() const
    { return _orderDependencies; }
    std::vector<std::string> const &outputDependencies() const
    { return _outputDependencies; }

public:
    std::vector<std::string> &inputDependencies()
    { return _inputDependencies; }
    std::vector<std::string> &orderDependencies()
    { return _orderDependencies; }
    std::vector<std::string> &outputDependencies()
    { return _outputDependencies; }

public:
    std::string const &dependencyInfo() const
    { return _dependencyInfo; }
    std::vector<AuxiliaryFile> const &auxiliaryFiles() const
    { return _auxiliaryFiles; }

public:
    std::string &dependencyInfo()
    { return _dependencyInfo; }
    std::vector<AuxiliaryFile> &auxiliaryFiles()
    { return _auxiliaryFiles; }

public:
    std::string const &logMessage() const
    { return _logMessage; }
    bool showEnvironmentInLog() const
    { return _showEnvironmentInLog; }

public:
    std::string &logMessage()
    { return _logMessage; }
    bool &showEnvironmentInLog()
    { return _showEnvironmentInLog; }
};

}

#endif // !__pbxbuild_ToolInvocation_h
