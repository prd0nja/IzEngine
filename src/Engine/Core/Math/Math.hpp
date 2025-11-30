#pragma once
#include "Engine/Base.hpp"

#include "Core/Interfaces/ISerializable.hpp"

#define GLM_FORCE_CTOR_INIT
#define GLM_FORCE_XYZW_ONLY
#define GLM_FORCE_LEFT_HANDED
#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/norm.hpp>

using vec2 = glm::vec2;
using vec3 = glm::vec3;
using vec4 = glm::vec4;
using mat3 = glm::mat3;
using mat4 = glm::mat4;

#define M_PI 3.14159265358979323846f
#define ANGLE2SHORT(x) (static_cast<int>((x) * 65536 / 360) & 65535)
#define SHORT2ANGLE(x) (x * (360.0f / 65536))

#define PITCH 0
#define YAW 1
#define ROLL 2

namespace glm
{
	SERIALIZE_NON_INTRUSIVE(vec2, x, y)
	SERIALIZE_NON_INTRUSIVE(vec3, x, y, z)
	SERIALIZE_NON_INTRUSIVE(vec4, x, y, z, w)
}

namespace IzEngine
{
	/// <summary>
	/// Math class.
	/// </summary>
	class API Math
	{
	public:
		/// <summary>
		/// Converts radians to degrees.
		/// </summary>
		/// <param name="radians">Radians value.</param>
		/// <returns>Degrees value.</returns>
		static float RadToDeg(float radians);

		/// <summary>
		/// Converts degrees to radians.
		/// </summary>
		/// <param name="degrees">Degrees value.</param>
		/// <returns>Radians value.</returns>
		static float DegToRad(float degrees);

		/// <summary>
		/// Normalizes an angle to the range of 0 to 90 degrees.
		/// </summary>
		/// <param name="angle">Angle in degrees.</param>
		/// <returns></returns>
		static float AngleNormalize90(float angle);

		/// <summary>
		/// Normalizes an angle to the range of -180 to 180 degrees.
		/// </summary>
		/// <param name="angle">Angle in degrees.</param>
		/// <returns></returns>
		static float AngleNormalize180(float angle);

		/// <summary>
		/// Normalizes an angle to the range of 0 to 360 degrees.
		/// </summary>
		/// <param name="angle">Angle in degrees.</param>
		/// <returns></returns>
		static float AngleNormalize360(float angle);

		/// <summary>
		/// Normalizes an angle to the range of -PI to PI radians.
		/// </summary>
		/// <param name="angle">Angle in radians.</param>
		/// <returns>Normalized angle in radians.</returns>
		static float AngleNormalizePI(float angle);

		/// <summary>
		/// Gets the delta angle of 2 angles.
		/// </summary>
		/// <param name="angle1">The first angle.</param>
		/// <param name="angle2">The second angle.</param>
		/// <returns></returns>
		static float AngleDelta(float angle1, float angle2);

		/// <summary>
		/// Checks if an angle is within the field of view (FOV).
		/// </summary>
		/// <param name="angle">Angle to check in radians.</param>
		/// <param name="tanHalfFov">The fov.</param>
		/// <returns>True if the angle is within the FOV, false otherwise.</returns>
		static bool AngleInFov(float angle, float tanHalfFov);

		/// <summary>
		/// Projects an angle onto the screen for rendering.
		/// </summary>
		/// <param name="angle">Angle to project in radians.</param>
		/// <param name="tanHalfFov">The fov.</param>
		/// <returns>Screen projection of the angle.</returns>
		static float AngleScreenProjection(float angle, float tanHalfFov);

		/// <summary>
		/// Converts a range specified by start and end angles to a range structure based on yaw.
		/// </summary>
		/// <param name="start">Starting angle in radians.</param>
		/// <param name="end">Ending angle in radians.</param>
		/// <param name="yaw">Yaw angle in radians.</param>
		/// <param name="tanHalfFov">The fov.</param>
		static vec3 AnglesToRange(float start, float end, float yaw, float tanHalfFov);

		/// <summary>
		/// Converts Euler angles to a forward, right, and up vector.
		/// </summary>
		/// <param name="angles">Euler angles in radians.</param>
		/// <param name="forward">Output forward vector.</param>
		/// <param name="right">Output right vector.</param>
		/// <param name="up">Output up vector.</param>
		static void AngleVectors(const vec3& angles, vec3& forward, vec3& right, vec3& up);

		/// <summary>
		/// Converts Euler angles to a up vector.
		/// </summary>
		/// <param name="angles">Euler angles in radians.</param>
		/// <returns>Up vector.</returns>
		static vec3 AnglesToUp(const vec3& angles);

		/// <summary>
		/// Converts Euler angles to a forward vector.
		/// </summary>
		/// <param name="angles">Euler angles in radians.</param>
		/// <returns>Forward vector.</returns>
		static vec3 AnglesToForward(const vec3& angles);

		/// <summary>
		/// Converts Euler angles to a right vector.
		/// </summary>
		/// <param name="angles">Euler angles in radians.</param>
		/// <returns>Right vector.</returns>
		static vec3 AnglesToRight(const vec3& angles);

		/// <summary>
		/// Angular distance between 2 values.
		/// </summary>
		/// <param name="value1">1st value.</param>
		/// <param name="value2">2nd value.</param>
		/// <returns></returns>
		static float AngularDistance(float value1, float value2);

		/// <summary>
		/// Converts a 3D vector to Euler angles (pitch, yaw, and roll) in radians.
		/// </summary>
		/// <param name="v">Input vector.</param>
		/// <returns>Euler angles in radians.</returns>
		static vec3 VectorToAngles(const vec3& v);

		/// <summary>
		/// Convert to BGRA.
		/// </summary>
		/// <param name="v">Color value.</param>
		/// <returns></returns>
		static int BGRA(const vec4& v);

		/// <summary>
		/// Convert to RGBA.
		/// </summary>
		/// <param name="v">Color value.</param>
		/// <returns></returns>
		static int RGBA(const vec4& v);
	};
}
