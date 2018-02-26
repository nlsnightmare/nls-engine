include("core/math")
include("core/entity")
include("core/input")

function Player()
   local self = Entity("box.png", "player")
   self.speed = 4;

   self.set_pos(5,5,-1)
   function self.update(dt)

      if get_key(keys.UP) then
	 self.translate(0, self.speed * dt,0)
      elseif get_key(keys.DOWN) then
	 self.translate(0, -self.speed * dt,0)
      end

      if get_key(keys.LEFT) then
	 self.translate(-self.speed * dt,0,0)
      elseif get_key(keys.RIGHT) then
	 self.translate(self.speed * dt,0,0)
      end
   end


   function self.on_collision(other,data)
      if math.abs(data.x) > math.abs(data.y) then
	 dx = (math.sign(data.x) - data.x)/2
	 self.translate(dx,0,0)
      else 
	 dy = (math.sign(data.y)-data.y)/2
	 self.translate(0, dy,0)
      end
   end

   function self.on_trigger(other, data)
      if math.abs(data.x) > math.abs(data.y) then
	 if data.x > 0 then
	    print("A")
	    print(( 1-data.x )/2)
	    self.translate(( 1-data.x )/2,0, 0)
	 else
	    print("b")
	    self.translate(-(data.x+1)/2,0,0)
	 end
      else 
	 if data.y > 0 then
	    print("c")
	    self.translate(0,( 1-data.y )/2,0)
	 else
	    print("d")
	    self.translate(0, -(data.y+1)/2,0)
	 end
      end
   end

   return self
end
