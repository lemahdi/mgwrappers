
/*
 Copyright (C) 2006 Mark Joshi
 Copyright (C) 2007, 2008 Eric Ehlers
 
 This file is part of XLW, a free-software/open-source C++ wrapper of the
 Excel C API - http://xlw.sourceforge.net/
 
 XLW is free software: you can redistribute it and/or modify it under the
 terms of the XLW license.  You should have received a copy of the
 license along with this program; if not, please email xlw-users@lists.sf.net
 
 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/
#ifdef _MSC_VER
#if _MSC_VER < 1250
#pragma warning(disable:4786)
#endif
#endif
#include "ParserData.h"

FunctionArgumentType::FunctionArgumentType(std::string NameIdentifier_,
                          const std::vector<std::string>& ConversionChain_,
                          const std::string& EXCELKey_)
                          :
                          NameIdentifier(NameIdentifier_),
                          ConversionChain(ConversionChain_),
                          EXCELKey(EXCELKey_)
                          {}
                          
     
const std::string& FunctionArgumentType::GetNameIdentifier() const
{
 return NameIdentifier;           
}
           
const std::vector<std::string>& FunctionArgumentType::GetConversionChain() const
{
 return ConversionChain;
}

FunctionArgumentType FunctionArgument::GetTheType() const
{
 return TheType;
}
const std::string& FunctionArgumentType::GetEXCELKey() const
{
    return EXCELKey;
}
    
std::string FunctionArgument::GetArgumentName() const
{
 return ArgumentName;
}

std::string FunctionArgument::GetArgumentDescription() const
{
 return ArgumentDescription;            
}

std::string FunctionArgument::GetArgumentDefaultvalue() const
{
 return ArgumentDefaultvalue;            
}

FunctionArgument::FunctionArgument(const FunctionArgumentType& TheType_,
                        std::string ArgumentName_,
                        std::string ArgumentDescription_,
						std::string ArgumentDefaultvalue_)
                        :
                        TheType(TheType_),
                        ArgumentName(ArgumentName_),
                        ArgumentDescription(ArgumentDescription_),
						ArgumentDefaultvalue(ArgumentDefaultvalue_)
{
}

std::string FunctionDescription::GetFunctionName() const
{
return FunctionName;
}

std::string FunctionDescription::GetFunctionDescription() const
{
return FunctionHelpDescription;
}

const FunctionArgument& FunctionDescription::GetArgument(
                                  unsigned long ArgumentNumber) const
{
   return Arguments.at(ArgumentNumber);
}

unsigned long FunctionDescription::NumberOfArguments() const
{
   return static_cast<unsigned long>(Arguments.size());
}
FunctionDescription::FunctionDescription(std::string FunctionName_,
                         std::string FunctionHelpDescription_,
                         std::string ReturnType_,
                         const std::string& ExcelKey_,
                         const std::vector<FunctionArgument>& Arguments_,
                         bool Volatile_,
                         bool Time_,
                         bool Threadsafe_)
                         :
                         FunctionName(FunctionName_),
                         FunctionHelpDescription(FunctionHelpDescription_),
                         ReturnType(ReturnType_),
                         ExcelKey(ExcelKey_),
                         Arguments(Arguments_),
                         Volatile(Volatile_),
                         Time(Time_),
                         Threadsafe(Threadsafe_)
{
}

 std::string FunctionDescription::GetExcelKey() const
 {
    return ExcelKey;
 }

std::string FunctionDescription::GetReturnType() const
{
    return ReturnType;
}

bool FunctionDescription::GetVolatile() const
{
    return  Volatile;
}

bool FunctionDescription::DoTime() const
{
    return  Time;
}

bool FunctionDescription::GetThreadsafe() const
{
    return  Threadsafe;
}
