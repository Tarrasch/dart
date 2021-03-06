/*
 * Copyright (c) 2011, Georgia Tech Research Corporation
 * All rights reserved.
 *
 * Author(s): Sehoon Ha <sehoon.ha@gmail.com>
 * Date: 06/12/2011
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

#ifndef KINEMATICS_SHAPE_H
#define KINEMATICS_SHAPE_H

#include <Eigen/Dense>

namespace renderer {
    class RenderInterface;
}

extern "C" { struct aiScene; }

namespace kinematics {
    class Transformation;

    class Shape {
    public:
        enum ShapeType {
            P_UNDEFINED,
            P_BOX,
            P_ELLIPSOID,
            P_CYLINDER,
            P_MESH
        };

        Shape(ShapeType _type = P_UNDEFINED);
        virtual ~Shape() {};

        inline void setColor(const Eigen::Vector3d& _color) { mColor = _color; }
        inline Eigen::Vector3d getColor() const { return mColor; }

        void setDim(const Eigen::Vector3d& _dim);
        inline Eigen::Vector3d getDim() const { return mDim; }

        inline void setTransform(const Eigen::Affine3d& _Transform ) { mTransform = _Transform; }
        inline Eigen::Affine3d getTransform() const { return mTransform; }

        inline void setOffset(Eigen::Vector3d _offset) { mTransform.translation() = _offset; }
        inline Eigen::Vector3d getOffset() const { return mTransform.translation(); }

        virtual Eigen::Matrix3d computeInertia(double _mass) { return Eigen::Matrix3d::Zero(); }

        inline void setVolume(double _v) { mVolume = _v; }
        inline double getVolume() const { return mVolume; }

        inline int getID() const { return mID; }
        inline ShapeType getShapeType() const { return mType; }

        virtual void draw(renderer::RenderInterface* _ri = NULL, const Eigen::Vector4d& _color=Eigen::Vector4d::Ones(), bool _useDefaultColor = true) const {}

    protected:
        virtual void computeVolume() {}

        virtual void initMeshes() {}

        ShapeType mType;    ///< Type of primitive; unknown in the general case
        Eigen::Vector3d mDim; ///< dimensions for bounding box
        double mVolume; ///< volume enclosed by the geometry

        int mID; // unique id
        Eigen::Vector3d mColor;		///< color for the primitive
        Eigen::Vector3d mOffset; ///< the origin of this primitive in the bodynode frame>
        Eigen::Affine3d mTransform; ///< Local Geometric transformation of the Shape w.r.t. parent frame

        static int mCounter;
    public:

        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    };

} // namespace kinematics

#endif // #ifndef KINEMATICS_PRIMITIVE_H

