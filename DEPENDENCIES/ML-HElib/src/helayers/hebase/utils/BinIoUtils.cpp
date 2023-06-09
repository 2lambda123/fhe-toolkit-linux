/*
 * MIT License
 *
 * Copyright (c) 2020 International Business Machines
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
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <vector>
#include "BinIoUtils.h"

using namespace std;

namespace helayers {

void BinIoUtils::writeString(std::ostream& out, const std::string& val)
{
  int sz = val.size() + 1;
  out.write(reinterpret_cast<const char*>(&sz), sizeof(sz));
  out.write(val.c_str(), sizeof(char) * sz);
}

void BinIoUtils::writeDouble(std::ostream& out, double val)
{
  out.write(reinterpret_cast<const char*>(&val), sizeof(double));
}

void BinIoUtils::writeLongDouble(std::ostream& out, long double val)
{
  out.write(reinterpret_cast<const char*>(&val), sizeof(long double));
}

void BinIoUtils::writeInt(std::ostream& out, int val)
{
  out.write(reinterpret_cast<const char*>(&val), sizeof(int));
}

void BinIoUtils::writeSizeT(std::ostream& out, size_t val)
{
  out.write(reinterpret_cast<const char*>(&val), sizeof(size_t));
}

void BinIoUtils::writeUnsignedInt(std::ostream& out, unsigned int val)
{
  out.write(reinterpret_cast<const char*>(&val), sizeof(unsigned int));
}

void BinIoUtils::writeLongUnsignedInt(std::ostream& out, long unsigned int val)
{
  out.write(reinterpret_cast<const char*>(&val), sizeof(long unsigned int));
}

void BinIoUtils::writeBool(std::ostream& out, bool val)
{
  out.write(reinterpret_cast<const char*>(&val), sizeof(bool));
}

std::string BinIoUtils::readString(std::istream& in)
{
  int sz;
  in.read(reinterpret_cast<char*>(&sz), sizeof(sz));
  char buff[sz];
  in.read(buff, sizeof(char) * sz);
  return string(buff);
}

double BinIoUtils::readDouble(std::istream& in)
{
  double val;
  in.read(reinterpret_cast<char*>(&val), sizeof(double));
  return val;
}

long double BinIoUtils::readLongDouble(std::istream& in)
{
  long double val;
  in.read(reinterpret_cast<char*>(&val), sizeof(long double));
  return val;
}

int BinIoUtils::readInt(std::istream& in)
{
  int val;
  in.read(reinterpret_cast<char*>(&val), sizeof(int));
  return val;
}

size_t BinIoUtils::readSizeT(std::istream& in)
{
  size_t val;
  in.read(reinterpret_cast<char*>(&val), sizeof(size_t));
  return val;
}

unsigned int BinIoUtils::readUnsignedInt(std::istream& in)
{
  unsigned int val;
  in.read(reinterpret_cast<char*>(&val), sizeof(unsigned int));
  return val;
}

long unsigned int BinIoUtils::readLongUnsignedInt(std::istream& in)
{
  long unsigned int val;
  in.read(reinterpret_cast<char*>(&val), sizeof(long unsigned int));
  return val;
}

bool BinIoUtils::readBool(std::istream& in)
{
  bool val;
  in.read(reinterpret_cast<char*>(&val), sizeof(bool));
  return val;
}
} // namespace helayers