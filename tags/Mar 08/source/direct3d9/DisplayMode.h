/*
* Copyright (c) 2007-2008 SlimDX Group
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/
#pragma once

#include "Enums.h"

namespace SlimDX
{
	namespace Direct3D9
	{
		[System::Runtime::InteropServices::StructLayout( System::Runtime::InteropServices::LayoutKind::Sequential )]
		public value class DisplayMode : System::IEquatable<DisplayMode>
		{
		public:
			property int Width;
            property int Height;
            property int RefreshRate;
            property Format Format;

			static bool operator == ( DisplayMode left, DisplayMode right );
			static bool operator != ( DisplayMode left, DisplayMode right );

			virtual int GetHashCode() override;
			virtual bool Equals( System::Object^ obj ) override;
			virtual bool Equals( DisplayMode other );
			static bool Equals( DisplayMode% value1, DisplayMode% value2 );
		};

		public ref class DisplayModeCollection : public System::Collections::Generic::ICollection<DisplayMode>
		{
		private:
			System::Collections::Generic::List<DisplayMode>^ list;

		internal:
			DisplayModeCollection( unsigned int adapter, Format format );

			virtual System::Collections::IEnumerator^ GetEnumerator2() = System::Collections::IEnumerable::GetEnumerator;

		public:
			virtual void Add( DisplayMode item ) { SLIMDX_UNREFERENCED_PARAMETER(item); throw gcnew System::NotSupportedException(); }
			virtual void Clear() { throw gcnew System::NotSupportedException(); }
			virtual bool Contains( DisplayMode item ) { return list->Contains( item ); }
			virtual void CopyTo( array<DisplayMode>^ array, int arrayIndex );
			virtual bool Remove( DisplayMode item ) { SLIMDX_UNREFERENCED_PARAMETER(item); throw gcnew System::NotSupportedException(); }

            property virtual int Count
            {
                int get() { return list->Count; }
            }

			virtual property bool IsReadOnly
			{
				bool get() { return true; }
			}

            property DisplayMode default[int]
			{
				DisplayMode get( int index )
				{
					return list[index];
				}
			}

			virtual System::Collections::Generic::IEnumerator<DisplayMode>^ GetEnumerator()
			{
                return list->GetEnumerator();
			}
		};
	}
}