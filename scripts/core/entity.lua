entities = {}

function find_entity(filter)
   if type(filter) == "string" then
      for _,e in pairs(entities) do
	 if e.get_name() == filter then
	    return e
	 end
      end
   end
   for _,e in pairs(entities) do
      if e.id == filter then
	 return e
      end
   end
end



function Entity(img, n1)
   local self = {}
   entities[#entities + 1] = self
   self.ptr = new_entity(img,n1)
   self.id = entity_get_id(self.ptr)

   self.position = {
      x = 0,
      y = 0,
      z = 0
   }

   self.scale = {
      x = 1,
      y = 1,
      z = 1
   }
   


   function self.get_pos()
      self.position.x,self.position.y,self.position.z = entity_get_position(self.ptr)
      return self.position.x,self.position.y,self.position.z
   end

   function self.get_name()
      return entity_get_name(self.ptr)
   end

   function self.set_pos(x,y,z)
      entity_set_position(self.ptr, x,y,z)
      self.position.x = x
      self.position.y = y
      self.position.z = z
   end

   function self.translate(dx,dy,dz)
      entity_translate(self.ptr, dx,dy,dz)
      self.position.x = self.position.x + dx
      self.position.y = self.position.y + dy
      self.position.z = self.position.z + dz
   end

   function self.get_pos()
      self.position.x,self.position.y,self.position.z = entity_get_position(self.ptr)
      return self.position
   end
   
   function self.get_scale()
      self.scale.x,self.scale.y,self.scale.z = entity_get_scale(self.ptr)
      return self.scale
   end
   function self.set_scale(x,y,z)
      entity_set_scale(self.ptr, x,y,z)
      self.scale.x = x
      self.scale.y = y
      self.scale.z = z
   end
   

   function self.update(dt)
   end



   function self.intersects(other)
      local x = self.position.x
      local y = self.position.y
      local w = self.scale.x
      local h = self.scale.y

      local ox = other.position.x
      local oy = other.position.y
      local ow = other.scale.x
      local oh = other.scale.y

      local int_x = x < ox + ow and x + w > ox
      local int_y = y < oy + oh and y + w > oy
      return int_x and int_y
   end


   function self.on_collision(other,data)
   end
   function self.on_trigger(other,data)
   end
   
   
   return self
end
