/*
 * Copyright (c) 2011, Georgia Tech Research Corporation
 * All rights reserved.
 *
 * Author(s):
 * Date:
 *
 * Geoorgia Tech Graphics Lab and Humanoid Robotics Lab
 *
 * Directed by Prof. C. Karen Liu and Prof. Mike Stilman
 * <karenliu@cc.gatech.edu> <mstilman@cc.gatech.edu>
 *
 * This file is provided under the following "BSD-style" License:
 *   Redistribution and use in source and binary forms, with or
 *   without modification, are permitted provided that the following
 *   conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 *   CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *   INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 *   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 *   USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *   AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *   ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *   POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef KINEMATICS_SHAPE_MESH_H
#define KINEMATICS_SHAPE_MESH_H

#include "Shape.h"

namespace kinematics {

    class ShapeMesh : public Shape {
    public:
        ShapeMesh(Eigen::Vector3d _dim, const aiScene *_mesh);

        inline const aiScene* getMesh() const { return mMesh; }
        inline void setMesh(const aiScene* _mesh) { mMesh = _mesh; }

        inline int getDisplayList() const { return mDisplayList; }
        inline void setDisplayList(int _index) { mDisplayList = _index; }

        void draw(renderer::RenderInterface* _ri = NULL, const Eigen::Vector4d& _col = Eigen::Vector4d::Ones(), bool _default = true) const;
        static const aiScene* loadMesh(const std::string& fileName);

        virtual Eigen::Matrix3d computeInertia(double _mass);

    private:
        void computeVolume();

        const aiScene *mMesh;
        int mDisplayList;	///< OpenGL DisplayList id for rendering

    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    };

} // namespace kinematics

#endif // #ifndef KINEMATICS_PRIMITIVE_MESH_H

