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

#ifndef SRC_HELAYERS_SIMPLEFCLAYER_H
#define SRC_HELAYERS_SIMPLEFCLAYER_H

#include "CipherMatrix.h"
#include "SimpleFcPlainLayer.h"

namespace helayers {

/// A class representing an encrypted fully connected layer
class SimpleFcLayer : public SimpleLayer
{

  HeContext& he;

  CipherMatrix weights;

  CipherMatrix bias;

public:
  SimpleFcLayer(HeContext& he);

  ~SimpleFcLayer();

  std::streamoff save(std::ostream& stream) const;

  std::streamoff load(std::istream& stream);

  void initFromLayer(const SimpleFcPlainLayer& fpl, int baseChainIndex = -1);

  CipherMatrix forward(const CipherMatrix& inVec) const;
};
} // namespace helayers

#endif /* SRC_HELAYERS_SIMPLEFCLAYER_H */
