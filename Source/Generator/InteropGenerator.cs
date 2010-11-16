﻿// Copyright (c) 2007-2010 SlimDX Group
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
using System;
using System.Collections.Generic;

namespace SlimDX.Generator
{
    public class InteropGenerator
    {
        private List<CSharpInteropCalliSignature> _methods;

        public InteropGenerator()
        {
            _methods = new List<CSharpInteropCalliSignature>();
        }

        public List<CSharpInteropCalliSignature> Methods
        {
            get { return _methods; }
        }


        public CSharpInteropCalliSignature Add(CSharpInteropCalliSignature method)
        {
            method.Index = Methods.Count;
            int indexOf = Methods.IndexOf(method);
            if (indexOf>=0)
                return Methods[indexOf];

            Methods.Add(method);
            return method;
        }

        public void Generate(string relativePath)
        {
            DynamicInterop.CalliSignature[] calliSignatures = new DynamicInterop.CalliSignature[_methods.Count];

            for (int i = 0; i < calliSignatures.Length; i++)
            {
                var inputSignature = _methods[i];
                var signature = new DynamicInterop.CalliSignature(inputSignature.Name, inputSignature.ReturnType,
                                                                  inputSignature.ParameterTypes.ToArray());
                calliSignatures[i] = signature;
            }

            DynamicInterop.Generate(calliSignatures, true, relativePath);
        }
    }
}